/******************************************************************************
 *       Project: AcceleratedCPP
 * (c) Copyright: 2022
 *       Company: Home
 *                All rights reserved
 * Secrecy Level: PUBLIC
 *****************************************************************************/

/**
 *    @file       example_a.cpp
 *    @author     VShylienkov
 *    @brief      Параграф 07. Упражнение 00. Страница 169.
 *
 *    Скомпилируйте, выполните и протестируйте программы, приведенные в этой главе.
 *    (Пример a. Страница 154)
 *
 *    @see        Эффективное программирование на C++.
 *    @see        Практическое программирование на примерах.
 *    @see        Эндрю Кёниг, Барбара Му. 2002.
 */

/**
 *   Version history:
 *
 *   2022-06-09   0.1.0   VShylienkov   Initial
 */

#include <iostream>
#include <map>
#include <string>

int main( )
{
    std::string s;
    std::map<std::string, int> counters;    // Храним каждое слово и соответствующий счетчик

    // Считываем входные данные, отслеживая количество вхождений каждого слова.
    while (std::cin >> s)
    {
        ++counters[s];
    }

    // Выводим слова и соответствующие счетчики
    for (std::map<std::string, int>::const_iterator it = counters.begin( ); it != counters.end( ); ++it)
    {
        std::cout << it->first << "\t" << it->second << std::endl;
    }
    return 0;
}