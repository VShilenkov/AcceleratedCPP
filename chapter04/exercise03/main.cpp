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
 *    @brief      Параграф 04. Упражнение 03. Страница 099.
 *
 *    Что произойдет, если переписать предыдущую программу так, чтобы она выводила
 *    числа (и их квадраты) до 1000 (но не включая значение 1000), и при этом пренеб-
 *    речь изменением аргументов, передаваемых в функцию setw()? ѕерепишите программу
 *    так, чтобы она была более защищенной "перед лицом" изменений, которые позво-
 *    ляют переменной i расти, не корректируя аргументы функции setw().
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
    const unsigned up_bound = 1000U;
    int maxlen = 0;

    for (unsigned t = up_bound; t > 0U; t /= 10U)
    {
        ++maxlen;
    }

    for (unsigned i = 0; i < up_bound; i++)
    {
        std::cout << std::setw(maxlen) << i << std::setw(2 * maxlen - 1) << i * i << std::endl;
    }

    return 0;
}
