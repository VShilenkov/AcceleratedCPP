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
 *    @brief      Параграф 05. Упражнение 00. Страница 127.
 *    
 *    Скомпилируйте, выполните и протестируйте программы, приведенные в этой главе.
 *    (Пример b. Страница 103)
 *
 *    @see        Эффективное программирование на C++.
 *    @see        Практическое программирование на примерах.
 *    @see        Эндрю Кёниг, Барбара Му. 2002.
 */
 
/**
 *   Version history:
 *
 *   2015-01-12   0.1.0   VShilenkov   Initial
 */

#include <fstream>
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
using std::ifstream;
using std::max;
using std::setprecision;
using std::streamsize;
using std::string;
using std::vector;

bool fgrade(const Student_info& s)
{
   return grade(s) < 60;
}

vector<Student_info> extract_fails(vector<Student_info>& students)
{
   vector<Student_info> fail;
   vector<Student_info>::size_type i = 0;

   while (i!=students.size())
   {
      if (fgrade(students[i]))
      {
         fail.push_back(students[i]);
         students.erase(students.begin() + i);
      }
      else
      {
         ++i;
      }
   }

   return fail;
}

int main()
{
   vector<Student_info> students, fail;
   Student_info record;
   string::size_type maxlen = 0;

   ifstream in("input.txt");

   while (read(in, record))
   {
      maxlen = max(maxlen, record.name.size());
      students.push_back(record);
   }

   fail = extract_fails(students);

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
