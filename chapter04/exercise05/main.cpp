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

using std::string;
using std::vector;

std::istream& operator>>(std::istream&, vector<string>&);

int main( )
{
    vector<string> words(16, "");
    std::cin >> words;

    if (!words.empty( ))
    {
        std::sort(words.begin( ), words.end( ));

        typedef vector<string>::const_iterator vec_string_i;

        string word  = *words.cbegin( );
        size_t count = 0U;
        for (vec_string_i i = words.cbegin( ); i != words.cend( ); ++i)
        {
            if (word != *i)
            {
                std::cout << word << '\t' << count << std::endl;
                word  = *i;
                count = 1;
            }
            else
            {
                ++count;
            }
        }
        std::cout << word << '\t' << count << std::endl << "Total words: " << words.size( );
    }

    return 0;
}

std::istream& operator>>(std::istream& in, vector<string>& vec)
{
    if (in)
    {
        vec.clear( );

        string word;
        while (in >> word)
        {
            vec.push_back(word);
        }

        in.clear( );
    }

    return in;
}
