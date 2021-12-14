/******************************************************************************
 *       Project: AcceleratedCPP
 * (c) Copyright: 2015
 *       Company: Home
 *                All rights reserved
 * Secrecy Level: PUBLIC
 *****************************************************************************/

/**
 *    @file    main.cpp
 *    @author  VShilenkov
 *    @brief   Параграф 05. Упражнение 06. Страница 128.
 *
 *    Перепишите функцию extract_fails из раздела 5.1.1 так, чтобы вместо удаления
 *    записи о каждом неуспевающем студенте из входного вектора v она копировала бы
 *    записи об успевающих стужентах в начало вектора v, а затем использовала функцию
 *    resize для удаления "лишних" элементов с конца вектора v. Как сравнить произво-
 *    дительность этой версии и варианта, произведенного в разделе 5.1.1?
 *
 *    @see     Эффективное программирование на C++.
 *    @see     Практическое программирование на примерах.
 *    @see     Эндрю Кёниг, Барбара Му. 2002.
 */
 
/**
 *   Version history:
 *
 *   2016-02-09   0.1.0   VShilenkov   Initial
 */

#include <fstream>      // IWYU pragma: keep 
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <list>
#include <vector>
#include <ctime>
#include "grade.hpp"
#include "Student_info.hpp"

// IWYU pragma: no_include <algorithm>

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::ifstream;
using std::max;
using std::setprecision;
using std::streamsize;
using std::string;
using std::list;
using std::vector;
using std::clock_t;
using std::clock;

typedef vector<Student_info> students_container;

bool fgrade(const Student_info& s)
{
   return grade(s) < 60;
}

students_container extract_fails(students_container& students)
{
   students_container fail;
   students_container::iterator f_iter = students.begin();
   students_container::iterator l_iter = students.end();

   l_iter--;

   students_container::size_type n = 0;

   while (f_iter <= l_iter)
   {
      if(!fgrade(*f_iter))
      {
         f_iter++;
         n++;
      }
      else
      {
         if (!fgrade(*l_iter))
         {
            fail.push_back(*f_iter);

            Student_info p = *l_iter;
            (*l_iter) = (*f_iter);
            (*f_iter) = p;

            f_iter++;
            n++;

         }
         else
         {
            fail.push_back(*l_iter);
         }

         l_iter--;      
      }
   }

   students.resize(n);

   return fail;
}

int main()
{
   students_container students, fail;
   Student_info record;
   string::size_type maxlen = 0;

   ifstream in("input.txt");

   while (read(in, record))
   {
      maxlen = max(maxlen, record.name.size());
      students.push_back(record);
   }

   clock_t time_start, time_end;

   time_start = clock();

   fail = extract_fails(students);

   time_end = clock();

   for (students_container::iterator i = students.begin(); i != students.end(); i++)
   {
      cout << i->name << string(maxlen - i->name.size() + 1, ' ');
      try
      {
         double final_grade = grade(*i);
         streamsize prec = cout.precision();
         cout << setprecision(3) << final_grade << setprecision(prec);
      }
      catch (domain_error e)
      {
         cout << e.what();
      }
      cout << endl;
   }

   cout << "Extracting fails took " << (double(time_end - time_start) / CLOCKS_PER_SEC) << " seconds" << endl;

   return 0;
}

