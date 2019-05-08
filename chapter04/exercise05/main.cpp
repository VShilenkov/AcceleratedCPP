/******************************************************************************
 *       Project: AcceleratedCPP
 * (c) Copyright: 2014
 *       Company: Home
 *                All rights reserved
 * Secrecy Level: PUBLIC
 *****************************************************************************/

/**
 *    @file       main.cpp
 *    @author     VShilenkov
 *    @brief      Параграф 04. Упражнение 05. Страница 099.
 *
 *    Напишите функцию, которая считывает слова из входного потока и сохраняет их
 *    в векторе. Используйте эту функцию для написания программ, которые подсчи-
 *    тывают количество слов во входном потоке, а также фиксируют, сколько раз
 *    встречается в нем каждое слово.
 *
 *    @see        Эффективное программирование на C++.
 *    @see        Практическое программирование на примерах.
 *    @see        Эндрю Кёниг, Барбара Му. 2002.
 */

/**
 *   Version history:
 *
 *   2014-12-29   0.1.0   VShilenkov   Initial
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

typedef std::vector<std::string> container_t;

std::istream& operator>>(std::istream&, container_t&);

int main( )
{
    container_t words(16, "");
    std::cin >> words;

    std::sort(words.begin( ), words.end( ));

    for (container_t::const_iterator i = words.cbegin( ), j = std::upper_bound(i, words.cend( ), *i);
         i != words.cend( );
         i = j, j = std::upper_bound(i, words.cend( ), *i))
    {
        std::cout << *i << '\t' << std::distance(i, j) << std::endl;
    }
    std::cout << "Total words: " << words.size( );

    return 0;
}

std::istream& operator>>(std::istream& in, container_t& vec)
{
    if (in)
    {
        vec.clear( );

        container_t::value_type word;
        while (in >> word)
        {
            vec.push_back(word);
        }

        in.clear( );
    }

    return in;
}
