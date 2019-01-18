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
 *    @brief      Параграф 00. Упражнение 04. Страница 027.
 *
 *    Напишите программу, которая выводит текст программы, выводящей текст
 *    "Привет, мир!".
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
    std::cout << "#include <iostream>"<<std::endl<<std::endl;
    std::cout << "int main()"<<std::endl<<'{'<<std::endl;
    std::cout << "\tstd::cout << \"Привет, мир!\";"<<std::endl<<std::endl;
    std::cout << "\treturn 0;"<<std::endl<<'}';

    return 0;
}
