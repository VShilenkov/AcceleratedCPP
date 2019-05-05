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
 *    @brief      Параграф 04. Упражнение 04. Страница 099.
 *
 *    А теперь измените свою программу вычисления квадратов, используя вместо
 *    int-значений значения типа double. Используйте манипуляторы для управления
 *    выводом данных так, чтобы значения были выровнены по столбцам.
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

//#include <iomanip>
#include <iostream>
#include <string>

int main( )
{
    using std::cout;
    using std::streamsize;
    using T = double;

    const T    up_bound   = 1000U;
    streamsize len_number = 0;

    for (T t = up_bound; t > 1.; t /= 10.)
    {
        ++len_number;
    }

    streamsize len_square = len_number << 1U;
    streamsize precision  = cout.precision( );
    streamsize width      = cout.width( );

    for (double i = .0; i < up_bound; i++)
    {
        cout.precision(len_number);
        cout.width(len_number);
        cout << i << ' ';
        cout.precision(len_square);
        cout.width(len_square);
        cout << i * i << std::endl;
    }

    cout.precision(precision);
    cout.width(width);

    return 0;
}
