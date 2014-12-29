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
 *    @brief      Параграф 04. Упражнение 06. Страница 099.
 *    
 *    Перепишите структуру Student_info для немедленного вычисления оценок и
 *    сохранения значения только итоговой оценки.
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
#include <iostream>
#include <ios>
#include <iomanip>
#include <vector>
#include <string>
#include <stdexcept>

using std::cin;
using std::cout;

using std::max;
using std::endl;
using std::sort;
using std::setprecision;

using std::vector;
using std::string;
using std::domain_error;
using std::istream;
using std::streamsize;

struct Student_info
{
   string name;
   double final_grade;
};

double median(vector<double> vec)
{
   typedef vector<double>::size_type vec_sz;

   vec_sz size = vec.size();
   if (size == 0)
      throw domain_error("Медиана пустого вектора.");

   sort(vec.begin(), vec.end());
   vec_sz mid = size / 2;

   return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

double grade(double midterm, double fin, double homework)
{
   return 0.2 * midterm + 0.4 * fin + 0.4 * homework;
}

double grade(double midterm, double fin, const vector<double>& hw)
{
   if (hw.size() == 0)
      throw domain_error("Студент не сделал ни одного домашнего задания ");
   return grade(midterm, fin, median(hw));
}

double grade(const Student_info& s)
{
   return s.final_grade;
}

istream& read_hw(istream& in, vector<double>& hw)
{
   if (in)
   {
      hw.clear();

      double x;
      while (in >> x)
         hw.push_back(x);

      in.clear();
   }
   return in;
}

istream& read(istream& in, Student_info& s)
{
   double midterm, fin;
   vector<double> homework;
   in >> s.name >> midterm >> fin;

   read_hw(in, homework);
   if (in)
   {
      s.final_grade = grade(midterm, fin, homework);
   }
   return in;
}

bool compare(const Student_info& x, const Student_info& y)
{
   return x.name < y.name;
}

int main()
{
   setlocale(LC_ALL, "Russian");

   vector<Student_info> students;
   Student_info record;
   string::size_type maxlen = 0;

   while (read(cin, record))
   {
      maxlen = max(maxlen, record.name.size());
      students.push_back(record);
   }

   sort(students.begin(), students.end(), compare);

   for (vector<Student_info>::size_type i = 0; i != students.size(); ++i)
   {
      cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');

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

}