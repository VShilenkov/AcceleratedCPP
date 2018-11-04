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
 *    @brief      Параграф 00. Упражнение 01. Страница 027.
 *
 *    Скомпилируйте и выполните программу, которая выводит текст "Привет, мир!".
 *
 *    @see        Эффективное программирование на C++.
 *    @see        Практическое программирование на примерах.
 *    @see        Эндрю Кёниг, Барбара Му. 2002.
 */

/**
 *   Version history:
 *
 *   2014-12-23   0.1.0   VShilenkov   Initial
 */

#include <iostream>

int main( )
{
    setlocale(LC_ALL, "Russian");

    std::cout << "Привет, мир!";

    return 0;
}