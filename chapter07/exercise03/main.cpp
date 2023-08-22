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
 *    @brief      Параграф 07. Упражнение 03. Страница 170.
 *
 *    Программу создания таблицы перекрестных ссылок из раздела 7.3 можно немного
 *    улучшить. В предыдущем её варианте предусмотрен многократный вывод одного
 *    и того же номера строки, если на этой входной строке некоторое слово
 *    встречается больше одного раза. Измените код так, чтобы при обнаружении
 *    нескольких вхождений одного и того же номера строки программа выводила
 *    этот номер только один раз.
 *
 *    @see        Эффективное программирование на C++.
 *    @see        Практическое программирование на примерах.
 *    @see        Эндрю Кёниг, Барбара Му. 2002.
 */

/**
 *   Version history:
 *
 *   2023-06-01   0.1.0   VShylienkov   Initial
 */

/**
 *   В исходной функции по поиску ссылок заменяем вектор на сет.
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
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
std::map<std::string, std::set<int>> xref(std::istream            &in,
                                          std::vector<std::string> find_words(const std::string &) = split)
{
    std::string                          line;
    int                                  line_number = 0;
    std::map<std::string, std::set<int>> ret;

    // Считываем следующую строку.
    while (getline(in, line))
    {
        ++line_number;

        // Разбиваем строку на слова.
        std::vector<std::string> words = find_words(line);

        // Помним, что каждое слово встречается на текущей строке
        for (std::vector<std::string>::const_iterator it = words.begin( ); it != words.end( ); ++it)
        {
            ret[*it].insert(line_number);
        }
    }
    return ret;
}

int main( )
{
    // Вызываем функцию xref, используя функцию split по умолчанию
    std::map<std::string, std::set<int>> ret = xref(std::cin);

    // Выводим результаты.
    for (auto it = ret.begin( ); it != ret.end( ); ++it)
    {
        // Выводим слово, ...
        std::cout << it->first << " встречается на строке (строках): ";

        // ... а за ним - один или несколько номеров строк.
        std::set<int>::const_iterator line_it = it->second.begin( );

        std::cout << *line_it;    // Выводим первый номер строки.

        ++line_it;
        // Выводим остальные номера строк, если таковые имеются.
        while (line_it != it->second.end( ))
        {
            std::cout << ", " << *line_it;
            ++line_it;
        }

        // Выводим символ новой строки, чтобы отделить каждое новое слово от следующего.
        std::cout << std::endl;
    }

    return 0;
}