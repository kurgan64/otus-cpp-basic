
#include <algorithm>
#include <cctype>
#include <chrono>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <mutex>
#include <string>
#include <thread>
#include <vector>
const size_t TOPK = 10;

using Counter = std::map<std::string, std::size_t>;

std::string tolower(const std::string& str);

void count_words_mutex(const std::string, Counter&, std::mutex&);
void count_words_atomic(const std::string, std::atomic<Counter>&);

void print_topk(std::ostream& stream, const Counter&, const size_t k);

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << " Usage : top_words[FILES...]" << std::endl;
    return 1;
  }
  int numberFilesProcessed = 0;
  size_t nthreads = std::thread::hardware_concurrency();
  auto start = std::chrono::high_resolution_clock::now();
  Counter freq_dict;
  std::mutex mtx;
  while (numberFilesProcessed <= argc - 2) {
    int countThreads = 0;
    if (argc - numberFilesProcessed - 1 > nthreads)
      countThreads = nthreads;
    else
      countThreads = argc - numberFilesProcessed - 1;
    std::vector<std::thread> workers;
    for (size_t i = 0; i < countThreads; i++) {
      std::string name{argv[i + numberFilesProcessed + 1]};
      workers.emplace_back(count_words_mutex, ref(name), ref(freq_dict),
                           ref(mtx));
    }
    for (size_t i = 0; i < countThreads; i++) {
      workers[i].join();
    }
    numberFilesProcessed += countThreads;
  }
  print_topk(std::cout, freq_dict, TOPK);
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed_ms =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "Elapsed time is " << elapsed_ms.count() << " us\n";
  return 0;
};

std::string tolower(const std::string& str) {
  std::string lower_str;
  std::transform(std::cbegin(str), std::cend(str),
                 std::back_inserter(lower_str),
                 [](unsigned char ch) { return std::tolower(ch); });
  return lower_str;
};

void print_topk(std::ostream& stream, const Counter& counter, const size_t k) {
  std::vector<Counter::const_iterator> words;
  words.reserve(counter.size());
  for (auto it = std::cbegin(counter); it != std::cend(counter); ++it) {
    words.push_back(it);
  }

  std::partial_sort(
      std::begin(words), std::begin(words) + k, std::end(words),
      [](auto lhs, auto& rhs) { return lhs->second > rhs->second; });

  std::for_each(std::begin(words), std::begin(words) + k,
                [&stream](const Counter::const_iterator& pair) {
                  stream << std::setw(4) << pair->second << " " << pair->first
                         << '\n';
                });
};
void count_words_mutex(const std::string name, Counter& counter,
                       std::mutex& mtx) {
  std::ifstream stream{name};
  if (!stream.is_open()) {
    std::cerr << "Failed to open file " << name << '\n';
    return;
  }
  // std::lock_guard lock(mtx);
  std::for_each(std::istream_iterator<std::string>(stream),
                std::istream_iterator<std::string>(),
                [&counter, &mtx](const std::string& s) {
                  std::lock_guard lock(mtx);
                  ++counter[tolower(s)];
                });
};