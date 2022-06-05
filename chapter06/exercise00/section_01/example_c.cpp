/******************************************************************************
 *       Project: AcceleratedCPP
 * (c) Copyright: 2022
 *       Company: Home
 *                All rights reserved
 * Secrecy Level: PUBLIC
 *****************************************************************************/

/**
 *    @file       example_c.cpp
 *    @author     VShilenkov
 *    @brief      Параграф 06. Упражнение 00. Страница 151.
 *
 *    Скомпилируйте, выполните и протестируйте программы, приведенные в этой главе.
 *    (Пример c. Страница 133)
 *
 *    @see        Эффективное программирование на C++.
 *    @see        Практическое программирование на примерах.
 *    @see        Эндрю Кёниг, Барбара Му. 2002.
 */

#include <algorithm>
#include <iostream>
#include <string>

bool is_palindrome(const std::string &s)
{
    return std::equal(s.begin( ), std::next(s.begin( ), (s.size( ) >> 1)), s.rbegin( ));
}

int main( )
{
    std::cout << std::boolalpha << is_palindrome("civic") << std::endl << is_palindrome("noon") << std::endl;
    return 0;
}