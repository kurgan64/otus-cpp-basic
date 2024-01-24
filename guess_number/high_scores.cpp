#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include "high_scores.h"

namespace high_score
{
    const std::string high_sore_filename = "high_scores.txt";
    static std::vector<std::pair<std::string, int>> high_scores;
    void zip_high_scores()
    {
        std::vector<std::pair<std::string, int>> new_high_scores;
        for (const auto &high_score : high_scores)
        {
            bool equal_high_score = false;
            for (auto &new_high_score : new_high_scores)
            {
                if (new_high_score.first == high_score.first)
                {
                    equal_high_score = true;
                    if (new_high_score.second > high_score.second)
                    {
                        new_high_score.second = high_score.second;
                    }
                }
            }
            if (!equal_high_score)
                new_high_scores.push_back(high_score);
        }
        high_scores = new_high_scores;
    }
    int read_high_scores_from_file()
    {
        std::ifstream in_file(high_sore_filename);
        if (!in_file.is_open())
        {
            std::cout << "Filed to open file for read " << high_sore_filename << std::endl;
            return -1;
        }

        std::cout << "High scores table:" << std::endl;
        std::string username;
        int high_score = 0;
        high_scores.clear();
        while (true)
        {
            in_file >> username;
            in_file >> high_score;
            in_file.ignore();
            if (in_file.fail())
                break;
            high_scores.push_back({username, high_score});
        }
        zip_high_scores();
        return 0;
    };
    void print_high_scores()
    {
        for (const auto &high_score : high_scores)
        {
            std::cout << high_score.first << "\t" << high_score.second << std::endl;
        }
    }
    void add_or_update_high_score(const std::string name, const int attempts)
    {
        bool equal_name = false;
        for (auto &high_score : high_scores)
        {
            if (high_score.first == name)
            {
                equal_name = true;
                if (high_score.second > attempts)
                    high_score.second = attempts;
            }
        }
        if (!equal_name)
            high_scores.push_back({name, attempts});
    }
    int save_score(const std::string name, const int attempts)
    {
        read_high_scores_from_file();
        add_or_update_high_score(name, attempts);
        std::ofstream out_file(high_sore_filename);
        if (!out_file.is_open())
        {
            std::cout << "Failed to open file for write" << high_sore_filename << std::endl;
            return -1;
        }
        for (const auto &high_score : high_scores)
        {
            out_file << high_score.first << ' ' << high_score.second << std::endl;
        }
        return 0;
    }
}