#include <iostream>
#include <istream>
#include "argument.h"
#include "high_scores.h"

int get_user_number()
{
    std::string str;
    bool str_is_integer;
    do
    {
        std::cin >> str;
        str_is_integer = true;
        for (int i = 0; i < str.size(); i++)
            if (!std::isdigit(static_cast<unsigned char>(str[i])))
                str_is_integer = false;
        if (!str_is_integer)
            std::cout << "Please, enter integer number!" << std::endl;

    } while (str_is_integer == false);
    return std::atoi(str.c_str());
};

int get_user_number2()
{
    int number;
    do
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> number;
        if (std::cin.fail())
            std::cout << "Bad number" << std::endl;
        else
            break;
    } while (true);

    return number;
}

int main(int args, char *argv[])
{
    int max_value;
    max_value = argument::parser_params(args, argv);
    if (max_value == 0)
        return 0;
    std::srand(std::time(nullptr));
    const int random_value = std::rand() % max_value;
    std::string name;
    std::cout << "Hi! Enter your name, please:" << std::endl;
    std::cin >> name;
    std::cout << name << " " << random_value << std::endl;
    int current_number;
    std::cout << "Enter yuor guess:" << std::endl;
    int attempts = 0;
    do
    {
        attempts++;
        current_number = get_user_number2();

        if (current_number < random_value)
            std::cout << "less than " << current_number << std::endl;
        else if (current_number > random_value)
            std::cout << "greater than " << current_number << std::endl;
        else
            std::cout << "you win! attempts = " << attempts << std::endl;
    } while (current_number != random_value);
    high_score::save_score(name, attempts);
    high_score::print_high_scores();
    return 0;
}