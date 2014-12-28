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
 *    @brief      Параграф 02. Упражнение 09. Страница 058.
 *    
 *    Напишите программу, которая бы предлагала пользователю ввести два числа, а
 *    затем сообщала, какое из них больше.
 *
 *    @see        Эффективное программирование на C++.
 *    @see        Практическое программирование на примерах.
 *    @see        Эндрю Кёниг, Барбара Му. 2002.
 */
 
/**
 *   Version history:
 *
 *   2014-12-28   0.1.0   VShilenkov   Initial
 */

#include <iostream>

int main()
{
   setlocale(LC_ALL, "Russian");
   std::cout << "Введите два числа: ";
   int a, b;
   std::cin >> a >> b;

   if (a == b) std::cout << "Числа равны!"; 
   else        std::cout << "Число " << ((a > b) ? a : b) << " большее";

   return 0;
}
