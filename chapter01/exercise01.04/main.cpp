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
 *    @brief      Параграф 01. Упражнение 04. Страница 036.
 *    
 *    Что можно сказать об этой программе? Что произойдет, если в третьей строке с
 *    конца две фигурные скобки }} заменить };}?
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
   { const std::string s = "одна строка";
     std::cout << s << std::endl;
   { const std::string s = "другая строка";
   std::cout << s << std::endl; }; }

   return 0;
} 
