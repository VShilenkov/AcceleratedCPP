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
 *    @brief      Параграф 04. Упражнение 02. Страница 099.
 *
 *    Напишите программу вычисления квадратов int-значений до 100. Эта программа
 *    должна вывести два столбца: в первом должно быть значение, а во втором - квадрат
 *    этого значения. Для управления выводом данных, т.е. чтобы выводимые значения
 *    были выровнены по столбцам, используйте функцию setw().
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

#include <iomanip>
#include <iostream>
#include <string>

int main( )
{
    const int up_bound = 100;
    int       maxlen   = 0;

    for (int t = up_bound; t > 0; t /= 10)
    {
        ++maxlen;
    }

    for (int i = 0; i < up_bound; i++)
    {
        std::cout << std::setw(maxlen) << i << std::setw(2 * maxlen - 1) << i * i << std::endl;
    }

    return 0;
}
