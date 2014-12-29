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
 *    @brief      Параграф 04. Упражнение 03. Страница 099.
 *
 *    А теперь измените свою программу вычисления квадратов, используя вместо
 *    int-значений значения типа double. Используйте манипуляторы для управления
 *    выводом данных так, чтобы значения были выровнены по столбцам.
 *
 *    @see        Эффективное программирование на C++.
 *    @see        Практическое программирование на примерах.
 *    @see        Эндрю Кёниг, Барбара Му. 2002.
 */
 
/**
 *   Version history:
 *
 *   2014-12-29   0.1.0   VShilenkov   Initial
 */

#include <iomanip>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::setprecision;
using std::streamsize;

int main()
{
   const double up_bound = 1000;
   streamsize len_number = 0;

   double t = up_bound;

   while (t > 1)
   {
      t /= 10;
      len_number++;
   }

   streamsize len_square = 2 * len_number;
   streamsize precision  = cout.precision();
   streamsize width      = cout.width();

   for (double i = 0; i < up_bound; i++)
   {
      
      cout << setprecision(len_number) << setw(len_number) << i << " "
           << setprecision(len_square) << setw(len_square) << i*i
           << endl;
   }

   cout << setprecision(precision) << setw(width);

   return 0;
}
