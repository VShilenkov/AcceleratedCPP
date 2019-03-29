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
 *    @brief      Параграф 02. Упражнение 08. Страница 058.
 *
 *    Напишите программу для вычисления произведения чисел из диапазона [1, 10)
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
    unsigned product = 2U;
    for (unsigned i = 3U; i < 10U; product *= i++)
        ;

    std::cout << product;
    return 0;
}
