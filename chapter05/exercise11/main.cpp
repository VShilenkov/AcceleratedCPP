/******************************************************************************
 *       Project: AcceleratedCPP
 * (c) Copyright: 2021
 *       Company: Home
 *                All rights reserved
 * Secrecy Level: PUBLIC
 *****************************************************************************/

/**
 *    @file       main.cpp
 *    @author     VShilenkov
 *    @brief      Параграф 5. Упражнение 11. Страница 128.
 *
 *    При обработке текстов зачастую полезно знать, имеет ли некоторое слово выступаю-
 *    выступающие или свисающие элементы букв. Выступающими являются части строчных букв,
 *    которые выступают выше линии текста (в английском алфавите к числу таких букв
 *    относятся b, d, f, h, k, l и t). Аналогично свисающими являются части строчных букв,
 *    которые находятся ниже текстовой линии (в английском алфавите к числу таких букв
 *    относятся g, j, p, q и y). Напишите программу для определения, имеет ли заданное
 *    слово какие-либо выступающие или свисающие элементы букв. Расширьте возмож-
 *    ности программы, "обучив" ее находить самое длинное слово в словаре, которое не
 *    имеет ни выступающих, ни свисающих элементов букв.
 *
 *    @see        Эффективное программирование на C++.
 *    @see        Практическое программирование на примерах.
 *    @see        Эндрю Кёниг, Барбара Му. 2002.
 */

/**
 *   Version history:
 *
 *   2021-12-15   0.1.0   VShilenkov   Initial
 */

#include <algorithm>
#include <cctype>
#include <fstream>    // IWYU pragma: keep
#include <iostream>
#include <set>
#include <string>
#include <vector>

bool hasUnderline(const std::string &s)
{
    const static std::set<char> underlying{'g', 'j', 'p', 'q', 'y'};

    auto r = std::find_if(s.begin( ), s.end( ), [](const std::string::value_type &c) -> bool {
        return underlying.count(c) > 0;
    });

    return r < s.end( );
}

bool hasUpperline(const std::string &s)
{
    const static std::set<char> upperlying{'b', 'd', 'f', 'h', 'k', 'l', 't'};

    auto r = std::find_if(s.begin( ), s.end( ), [](const std::string::value_type &c) -> bool {
        return (std::isupper(c)) || (upperlying.count(c) > 0);
    });

    return r < s.end( );
}

int main( )
{
#ifndef INPUT_FILE
#    error "INPUT_FILE has to be deined"
#endif
    std::fstream input_stream(INPUT_FILE);

    std::set<std::string> unique_words;

    while (input_stream.good( ))
    {
        std::string word;
        input_stream >> word;
        unique_words.insert(word);
    }

    std::vector<std::string> dictionary(unique_words.begin( ), unique_words.end( ));

    auto n =
        std::remove_if(dictionary.begin( ), dictionary.end( ), [](const std::set<std::string>::value_type &s) -> bool {
            return hasUnderline(s) || hasUpperline(s);
        });

    auto m = std::max_element(dictionary.begin( ),
                              n,
                              [](const std::set<std::string>::value_type &l,
                                 const std::set<std::string>::value_type &r) -> bool { return l.size( ) < r.size( ); });

    if (m != n)
    {
        std::cout << *m << '\t' << m->size( ) << std::endl;
    }

    return 0;
}