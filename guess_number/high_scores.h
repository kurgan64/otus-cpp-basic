#pragma once
#include <string>
#include <vector>

namespace high_score
{
    int read_high_scores_from_file();
    int save_score(const std::string &name, const int attempt);
    void print_high_scores();
}