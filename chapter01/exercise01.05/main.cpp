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
 *    @brief      Параграф 01. Упражнение 05. Страница 037.
 *
 *    Допустима ли такая программа? Если да, то что она делает? Если нет, то ответьте,
 *    почему, и предложите допустимый вариант.
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

#include <iostream>
#include <string>

int main()
{
   { std::string s = "одна строка";
   { std::string x = s + ", действительно";
     std::cout << s << std::endl; //}
     std::cout << x << std::endl; }
   }
   return 0;
}


// main.cpp: In function 'int main()' :
// main.cpp : 37 : 19 : error : 'x' was not declared in this scope
// std::cout << x << std::endl;
//              ^