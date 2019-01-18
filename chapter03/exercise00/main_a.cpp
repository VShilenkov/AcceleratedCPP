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
 *    @brief      Параграф 03. Упражнение 00. Страница 074.
 *
 *    Скомпилируйте, выполните и протестируйте программы, приведенные в этой главе.
 *    (Пример a. Страница 059)
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

#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;

int main()
{
   // Запрашиваем и считываем имя студента.
   cout << "Пожалуйста, введите свое имя: ";
   string name;
   cin >> name;
   cout << "Привет, " << name << "!" << endl;

   // Запрашиваем и считываем оценки по экзаменам,
   // проведенным в середине и в конце семестра.
   cout << "Пожалуйста, введите оценки по экзаменам "
      "в середине и в конце семестра: ";
   double midterm, fin;
   cin >> midterm >> fin;

   // Запрашиваем оценки за выполнение домашних заданий.
   cout << "Введите все оценки за выполнение домашних заданий, "
      "завершив ввод признаком конца файла: ";

   // Количество и сумма оценок, прочитанных до сих пор.
   int count = 0;
   double sum = 0;

   // Переменная, в которую выполняется считывание данных.
   double x;

   // Инвариант:
   // Мы прочитали пока count оценок, и
   // переменная sum содержит сумму первых count оценок.
   while (cin >> x)
   {
      ++count;
      sum += x;
   }

   // Выводим результат.
   streamsize prec = cout.precision();
   cout << "Ваша итоговая оценка равна " << setprecision(3)
      << 0.2 * midterm + 0.4 * fin + 0.4 * sum / count
      << setprecision(prec) << endl;

   return 0;
}
