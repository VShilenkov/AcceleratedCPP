/******************************************************************************
 *       Project: AcceleratedCPP
 * (c) Copyright: 2015
 *       Company: Home
 *                All rights reserved
 * Secrecy Level: PUBLIC
 *****************************************************************************/

/**
 *    @file       main.cpp
 *    @author     VShilenkov
 *    @brief      Параграф 05. Упражнение 03. Страница 127.
 *    
 *    Используя средство typedef, можно написать одну версию программы, которая
 *    реализует либо vector-, либо list-ориентированное решение. Напишите и про-
 *    тестируйте эту версию программы.
 *
 *    @see        Эффективное программирование на C++.
 *    @see        Практическое программирование на примерах.
 *    @see        Эндрю Кёниг, Барбара Му. 2002.
 */
 
/**
 *   Version history:
 *
 *   2015-01-28   0.1.0   VShilenkov   Initial
 */

#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <list>
#include <vector>
#include <ctime>
#include "grade.hpp"
#include "Student_info.hpp"

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

typedef list<Student_info> students_container;

bool fgrade(const Student_info& s)
{
   return grade(s) < 60;
}

students_container extract_fails(students_container& students)
{
   students_container fail;
   students_container::iterator iter = students.begin();

   while (iter != students.end())
   {
      if (fgrade(*iter))
      {
         fail.push_back(*iter);
         iter = students.erase(iter);
      }
      else
      {
         ++iter;
      }
   }

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

