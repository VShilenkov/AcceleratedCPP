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
 *    @brief      Параграф 03. Упражнение 03. Страница 074.
 *
 *    Напишите программу для вывода длины самого длинного и самого короткого
 *    string-значения во введенных данных.
 *
 *    @see        Эффективное программирование на C++.
 *    @see        Практическое программирование на примерах.
 *    @see        Эндрю Кёниг, Барбара Му. 2002.
 */

/**
 *   Version history:
 *
 *   2014-12-28   0.1.0   VShilenkov   Initial
 */

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main( )
{
    string word;

    if (cin >> word)
    {
        string longestWord(word);
        string shortestWord(word);

        while (cin >> word)
        {
            if (word.size( ) > longestWord.size( ))
            {
                longestWord = word;
            }
            if (word.size( ) < shortestWord.size( ))
            {
                shortestWord = word;
            }
        }

        cout << "Самое длинное слово: " << longestWord << ". Его длина: " << longestWord.size( ) << endl;
        cout << "Самое короткое слово: " << shortestWord << ". Его длина: " << shortestWord.size( ) << endl;
    }
    else
    {
        cout << "Не введено ни единого слова.";
        return 1;
    }

    return 0;
}
