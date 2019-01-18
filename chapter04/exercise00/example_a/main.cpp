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
 *    (Пример a. Страница 084)
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
#include <iostream>
#include <ios>
#include <iomanip>
#include <vector>
#include <string>
#include <stdexcept>

using std::cin;
using std::cout;

using std::endl;
using std::sort;
using std::setprecision;

using std::vector;
using std::string;
using std::domain_error;
using std::istream;
using std::streamsize;


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

int main()
{
   cout << "Пожалуйста, введите свое имя: ";
   string name;
   cin >> name;
   cout << "Привет, " << name << "!" << endl;

   cout << "Пожалуйста, введите оценки по экзаменам, "
      "проведенным в середине и конце семестра: ";
   double midterm, fin;
   cin >> midterm >> fin;

   cout << "Введите все оценки за выполнение домашних заданий, "
      "завершив ввод признаком конца файла: ";

   vector<double> homework;

   read_hw(cin, homework);

   try
   {
      double final_grade = grade(midterm, fin, homework);
      streamsize prec = cout.precision();
      cout << "Ваша итоговая оценка равна " << setprecision(3)
         << final_grade << setprecision(prec) << endl;
   }
   catch (domain_error)
   {
      cout << "Вы должны ввести свои оценки. "
         << "Пожалуйста, попытайтесь снова." << endl;
      return 1;
   }

   return 0;
}

