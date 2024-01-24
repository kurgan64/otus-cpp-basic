#include "argument.h"
#include <iostream>
#include "high_scores.h"

namespace argument
{
    bool is_max_or_level = false;
    bool is_present_level_max()
    {
        if (is_max_or_level)
        {
            std::cout << "-max & -level cannot be specified together" << std::endl;
            return true;
        }
        is_max_or_level = true;
        return false;
    };
    int parser_params(const int args, char **argv)
    {
        int max_value = 0;
        if (args > 1)
        {
            for (int i = 1; i < args;)
            {
                std::string arg_value{argv[i]};
                int parameter_value = 0;
                if (arg_value == "-table")
                {
                    max_value = 0;
                    high_score::read_high_scores_from_file();
                    high_score::print_high_scores();
                    break;
                }
                if (arg_value == "-level")
                {
                    if (is_present_level_max())
                    {
                        max_value = 0;
                        break;
                    }
                    parameter_value = std::stoi(argv[i + 1]);
                    switch (parameter_value)
                    {
                    case 1:
                        max_value = 10;
                        break;
                    case 2:
                        max_value = 50;
                    default:
                        max_value = 100;
                        break;
                    }
                    i += 2;
                }
                if (arg_value == "-max")
                {
                    if (is_present_level_max())
                    {
                        max_value = 0;
                        break;
                    }
                    parameter_value = std::stoi(argv[i + 1]);
                    if (parameter_value > 0 && parameter_value <= 100)
                    {
                        max_value = parameter_value;
                    }
                    else
                        max_value = 100;
                    i += 2;
                }
            }
        }
        else
            max_value = 100;

        return max_value;
    };
}