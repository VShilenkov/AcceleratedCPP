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
 *    @brief      �������� 05. ���������� 02. �������� 127.
 *    
 *    �������� ����������� ������ ��������� ��� ���������� �������� ������ ���-
 *    ������ �� ���� ��������, ������� �������� ������ � ������������ ���������. ����-
 *    ���� ��� ���� ������� � �������������� �������. ���������� ������� � ���������-
 *    ��������� ��� ������������� ������� ������ � 10, 1000 � 10 000 ��������.
 *    [������]
 *    
 *    @see        ����������� ���������������� �� C++.
 *    @see        ������������ ���������������� �� ��������.
 *    @see        ����� ʸ���, ������� ��. 2002.
 */

/**
 *   Version history:
 *
 *   2015-01-15   0.1.0   VShilenkov   Initial
 */

#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
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
using std::vector;
using std::clock_t;
using std::clock;

bool fgrade(const Student_info& s)
{
   return grade(s) < 60;
}

vector<Student_info> extract_fails(vector<Student_info>& students)
{
   vector<Student_info> fail;
   vector<Student_info>::iterator iter = students.begin();

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
   vector<Student_info> students, fail;
   Student_info record;
   string::size_type maxlen = 0;

   ifstream in("input10000.txt");

   while (read(in, record))
   {
      maxlen = max(maxlen, record.name.size());
      students.push_back(record);
   }

   clock_t time_start, time_end;

   time_start = clock();

   fail = extract_fails(students);

   time_end = clock();

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

   cout << "Extracting fails took " << (double(time_end - time_start) / CLOCKS_PER_SEC) << " seconds" << endl;

   return 0;
}