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
 *    @brief      Параграф 00. Упражнение 05. Страница 027.
 *
 *    Эта программа допустима? Почему?
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
int main( ) std::cout << "Привет, мир!" << std::endl;

// main.cpp:28:12: error: expected initializer before 'std'
// int main() std::cout << "Привет, мир!" << std::endl;
//           ^
