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
 *    @brief      Параграф 04. Упражнение 07. Страница 099.
 *
 *    Напишите программу вычисления среднего арифметического от чисел, содержа-
 *    щихся в векторе типа vector<double>.
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

#include <iostream>
#include <stdexcept>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::domain_error;
using std::vector;

double arithmetic_mean(const vector<double>& src)
{
   if (src.size() == 0)
      throw domain_error("Empty vector");
   double sum = 0;
   for (size_t i = 0; i < src.size(); i++)
   {
      sum += src[i];
   }

   return sum / src.size();
}

int main()
{
   vector<double> d;
   double number;
   while (cin >> number)
      d.push_back(number);

   try
   {
      cout << arithmetic_mean(d);
   }
   catch (domain_error e)
   {
      cout << e.what() << endl;
   }

   return 0;
}
