/******************************************************************************
 *       Project: AcceleratedCPP
 * (c) Copyright: 2022
 *       Company: Home
 *                All rights reserved
 * Secrecy Level: PUBLIC
 *****************************************************************************/

/**
 *    @file       example_b.cpp
 *    @author     VShilenkov
 *    @brief      Параграф 06. Упражнение 00. Страница 151.
 *
 *    Скомпилируйте, выполните и протестируйте программы, приведенные в этой главе.
 *    (Пример b. Страница 131)
 *
 *    @see        Эффективное программирование на C++.
 *    @see        Практическое программирование на примерах.
 *    @see        Эндрю Кёниг, Барбара Му. 2002.
 */

/**
 *   Version history:
 *
 *   2022-03-15   0.1.0   VShilenkov   Initial
 */

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

#include "vshlib_vector.hpp"

// Возвращает значение true, если аргумент - пробел или
// символ, подобный ему; в противном случае
// возвращает значение false.
bool space(char c)
{
    return std::isspace(c);
}

// Возвращает значение false, если аргумент - пробел или
// символ, подобный ему; в противном случае
// возвращает значение true.
bool not_space(char c)
{
    return !std::isspace(c);
}

std::vector<std::string> split(const std::string &str)
{
    typedef std::string::const_iterator iter;

    std::vector<std::string> ret;

    iter i = str.begin( );
    while (i != str.end( ))
    {
        // Игнорируем ведущие пробелы.
        i = std::find_if(i, str.end( ), not_space);

        // Находим конец следующего слова.
        iter j = std::find_if(i, str.end( ), space);

        // Копируем символы из диапазона [i, j).
        if (i != str.end( ))
        {
            ret.emplace_back(i, j);
        }
        i = j;
    }
    return ret;
}

int main( )
{
    using std::pair;
    using std::string;
    using std::vector;
    vector<pair<string, vector<string>>> test_cases{{"Hello world!", {"Hello", "world!"}}};

    unsigned test_counter{0};
    for (auto &test : test_cases)
    {
        const auto &actual   = split(test.first);
        const auto &expected = test.second;
        if (actual == expected)
        {
            std::cout << "true" << std::endl;
        }
        else
        {
            std::cout << "false " << actual << " " << expected << std::endl;
        }
    }
}