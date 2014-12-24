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
 *    @brief      Параграф 01. Упражнение 02. Страница 036.
 *
 *    Допустимы ли такие определения? Почему?
 *
 *    @see        Эффективное программирование на C++.
 *    @see        Практическое программирование на примерах.
 *    @see        Эндрю Кёниг, Барбара Му. 2002.
 */
 
/**
 *   Version history:
 *
 *   2014-12-24   0.1.0   VShilenkov   Initial
 */

#include <string>

int main() 
{ 
   const std::string excalm = "!";
   const std::string message = "Привет" + ", мир" + excalm;

   return 0;
}

// main.cpp: In function 'int main()':
// main.cpp:32 : 43 : error : invalid operands of types 'const char [7]' and 'const char [6]' to binary 'operator+'
// const std::string message = "Привет" + ", мир" + excalm;
//                                        ^
