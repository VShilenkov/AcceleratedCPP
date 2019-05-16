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
 *    @brief      Параграф 04. Упражнение 07. Страница 099.
 *
 *    Напишите программу вычисления среднего арифметического от чисел, содержа-
 *    щихся в векторе типа vector<double>.
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

#include "numeric.hpp"

#include <iostream>

typedef std::vector<double> container_t;

std::istream& operator>>(std::istream&, container_t&);

int main( )
{
    container_t d;
    std::cin >> d;

    std::cout << vsh::arithmetic_mean(d.begin( ), d.end( )) << std::endl;

    return 0;
}

std::istream& operator>>(std::istream& in, container_t& hw)
{
    if (in)
    {
        hw.clear( );
        container_t::value_type x;
        while (in >> x)
        {
            hw.push_back(x);
        }
        in.clear( );
    }
    return in;
}
