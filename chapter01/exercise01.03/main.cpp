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
 *    @brief      Параграф 01. Упражнение 03. Страница 036.
 *    
 *    Допустима ли следующая программа? Если да, то что она делает? Если нет, то
 *    почему?
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
   setlocale(LC_ALL, "Russian");

   { const std::string s = "одна строка";
     std::cout << s << std::endl; }

   { const std::string s = "другая строка";
   std::cout << s << std::endl; }

   return 0;
}