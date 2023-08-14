/******************************************************************************
 *       Project: AcceleratedCPP
 * (c) Copyright: 2023
 *       Company: Home
 *                All rights reserved
 * Secrecy Level: PUBLIC
 *****************************************************************************/

/**
 *    @file       main.cpp
 *    @author     VShylienkov
 *    @brief      Параграф 07. Упражнение 01. Страница 169.
 *
 *    Дополните приведенную в разделе 7.2 программу так, чтобы она выводила
 *    результаты, отсортированные по частоте вхождения слов. Это значит, что
 *    сначала должны быть выведены слова, встречающиеся один раз, за ними -
 *    слова, встречающиеся два раза, и т.д.
 *
 *    @see        Эффективное программирование на C++.
 *    @see        Практическое программирование на примерах.
 *    @see        Эндрю Кёниг, Барбара Му. 2002.
 */

/**
 *   Version history:
 *
 *   2023-08-14   0.1.0   VShylienkov   init
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

bool space(char c)
{
    return std::isspace(c);
}

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

// Находим все строк, в которых есть каждое слово
// из исходного текста.
std::map<std::string, std::vector<int>> xref(std::istream            &in,
                                             std::vector<std::string> find_words(const std::string &) = split)
{
    std::string                             line;
    int                                     line_number = 0;
    std::map<std::string, std::vector<int>> ret;

    // Считываем следующую строку.
    while (getline(in, line))
    {
        ++line_number;

        // Разбиваем строку на слова.
        std::vector<std::string> words = find_words(line);

        // Помним, что каждое слово встречается на текущей строке
        for (std::vector<std::string>::const_iterator it = words.begin( ); it != words.end( ); ++it)
        {
            ret[*it].push_back(line_number);
        }
    }
    return ret;
}

int main( )
{
    // Вызываем функцию xref, используя функцию split по умолчанию
    std::map<std::string, std::vector<int>> ret = xref(std::cin);
    std::map<int, std::vector<std::string>> frequency;

    for (const auto &p : ret)
    {
        frequency[p.second.size( )].push_back(p.first);
    }

    // Выводим результаты.
    for (auto f = frequency.begin( ); f != frequency.end( ); ++f)
    {
        for (const auto &w : f->second)
        {
            // Выводим слово, ...
            std::cout << w << " встречается " << f->first << " раз(а) на строке (строках): ";

            // ... а за ним - один или несколько номеров строк.
            std::vector<int>::const_iterator line_it = ret[w].begin( );

            std::cout << *line_it;    // Выводим первый номер строки.

            ++line_it;
            // Выводим остальные номера строк, если таковые имеются.
            while (line_it != ret[w].end( ))
            {
                std::cout << ", " << *line_it;
                ++line_it;
            }

            // Выводим символ новой строки, чтобы отделить каждое новое слово от следующего.
            std::cout << std::endl;
        }
    }

    return 0;
}