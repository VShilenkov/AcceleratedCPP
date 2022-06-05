/******************************************************************************
 *       Project: AcceleratedCPP
 * (c) Copyright: 2015
 *       Company: Home
 *                All rights reserved
 * Secrecy Level: PUBLIC
 *****************************************************************************/

/**
 *    @file       main.cpp
 *    @author     VShylienkov
 *    @brief      Параграф 06. Упражнение 03. Страница 151.
 *
 *    Что делает этот фрагмент программы? Напишите программу, которая бы включала
 *    этот фрагмент, скомпилируйте и выполните ее.
 *
 *    @see        Эффективное программирование на C++.
 *    @see        Практическое программирование на примерах.
 *    @see        Эндрю Кёниг, Барбара Му. 2002.
 */

/**
 *   Version history:
 *
 *   2022-06-05   0.1.0   VShylienkov   Initial
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main( )
{
    std::vector<int> u(10,100);
    std::vector<int> v;
    std::copy(u.begin(), u.end(), v.begin());
    return 0;
}