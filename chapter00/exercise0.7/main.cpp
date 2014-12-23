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
 *    @brief      Параграф 00. Упражнение 07. Страница 028.
 *
 *    А что вы скажете об этой программе?
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
int main()
{
/* Этот коментарий может занимать несколько строк, поскольку
в качестве начального и конечного ограничителей он использует
символы /* и */. */
std::cout << "Этот вариант программы будет работать?" << std::endl;
return 0;
}

//main.cpp: In function 'int main()':
//main.cpp:32 : 16 : error : expected primary - expression before '.' token
//символы /* ш */. * /
//               ^
//main.cpp : 32 : 18 : error : expected unqualified - id before '*' token
//символы /* ш */. * /
//                 ^
//main.cpp : 32 : 19 : error : expected primary - expression before '/' token
//символы /* ш */. * /
//                   ^