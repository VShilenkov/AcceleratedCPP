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
 *    @brief      Параграф 04. Упражнение 02. Страница 099.
 *
 *    Напишите программу вычисления квадратов int-значений до 100. Эта программа
 *    должна вывести два столбца: а пераом должно быть значение, а во втором - квадрат
 *    этого значения. Для управления выводом данных, т.е. чтобы выводимые значения
 *    были выровнены по столбцам, используйте функцию setw().
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
using std::streamsize;

int main()
{
   const int up_bound = 100;
   streamsize maxlen = 0;

   int t = up_bound;
   while (t > 0)
   {
      t /= 10;
      maxlen++;
   }
   

   for (int i = 0; i < up_bound; i++)
   {
      cout << setw(maxlen) << i << setw(2 * maxlen - 1) << i*i << endl;
   }

   return 0;
}