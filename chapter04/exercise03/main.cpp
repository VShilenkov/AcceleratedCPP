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
 *    Что произойдет, если переписать предыдущую программу так, чтобы она выводила
 *    числа (и их квадраты) до 1000 (но не включая значение 1000), и при этом пренеб-
 *    речь изменением аргументов, передаваемых в функцию setw()? Перепишите программу
 *    так, чтобы она была более защищенной "перед лицом" изменений, которые позво-
 *    ляют переменной i расти, не корректируя аргументы функции setw().
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
   const int up_bound = 1000;
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
