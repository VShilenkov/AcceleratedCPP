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
*    (Пример b. Страница 071)
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

#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::sort;
using std::string;
using std::streamsize;
using std::vector;

int main()
{
   // Запрашиваем и читаем имя студента.
   cout << "Пожалуйста, введите свое имя: ";
   string name;
   cin >> name;
   cout << "Привет, " << name << "!" << endl;

   // Запрашиваем и читаем оценки по экзаменам,
   // проведенным в середине и в конце семестра.
   cout << "Пожалуйста, введите оценки по экзаменам "
      "в середине и в конце семестра: ";
   double midterm, fin;
   cin >> midterm >> fin;

   // Запрашиваем оценки за выполнение домашних заданий.
   cout << "Введите все оценки за выполнение домашних заданий, "
      "завершив ввод признаком конца файла: ";
   vector<double> homework;
   double x;

   // Инвариант: объект homework содержит все оценки
   // за домашние задания, введенные до сих пор
   while (cin >> x)
      homework.push_back(x);

   // Проверяем, ввел ли студент оценки за домашние задания.
   typedef vector<double>::size_type vec_sz;
   vec_sz size = homework.size();

   if (size == 0)
   {
      cout << endl << "Необходимо ввести оценки для расчета. " 
         "Пожалуйста, попытайтесь снова. " << endl;
      return 1;
   }

   // Сортируем оценки.
   sort(homework.begin(), homework.end());

   // Вычисляем медианную оценку вектора homework.
   vec_sz mid = size / 2;
   double median;
   median = size % 2 == 0 ? (homework[mid] + homework[mid - 1]) / 2
      : homework[mid];

   // Вычисляем и выводим результат.
   streamsize prec = cout.precision();
   cout << "Ваша итоговая оценка равна " << setprecision(3)
      << 0.2 * midterm + 0.4 * fin + 0.4 * median
      << setprecision(prec) << endl;

   return 0;

}