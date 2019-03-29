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
 *    @brief      Параграф 02. Упражнение 10. Страница 058.
 *
 *    Поясните каждое из применений префикса std:: в следующей программе.
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

int main( )
{
    int k = 0;
    int n = 10;
    while (k != n)
    {
        // Инвариант: пока мы вывели
        // k символов "звездочка"
        using std::cout;
        cout << "*";
        ++k;
    }
    std::cout << std::endl;    // Здесь нужен префикс std::.
    return 0;
}
