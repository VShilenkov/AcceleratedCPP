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
 *    @brief      Параграф 04. Упражнение 00. Страница 099.
 *
 *    Скомпилируйте, выполните и протестируйте программы, приведенные в этой главе.
 *    (Пример c. Страница 096)
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

#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.hpp"
#include "Student_info.hpp"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::max;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

int main()
{
   vector<Student_info> students;
   Student_info record;
   string::size_type maxlen = 0;

   while (read(cin, record))
   {
      maxlen = max(maxlen, record.name.size());
      students.push_back(record);
   }

   sort(students.begin(), students.end(), compare);

   for (vector<Student_info>::size_type i = 0; i != students.size(); i++)
   {
      cout << students[i].name << string(maxlen - students[i].name.size() + 1, ' ');
      try
      {
         double final_grade = grade(students[i]);
         streamsize prec = cout.precision();
         cout << setprecision(3) << final_grade << setprecision(prec);
      }
      catch (domain_error e)
      {
         cout << e.what();
      }
      cout << endl;
   }

   return 0;
}