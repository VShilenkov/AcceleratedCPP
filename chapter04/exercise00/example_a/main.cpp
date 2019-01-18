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
 *    @brief      �������� 04. ���������� 00. �������� 099.
 *    
 *    �������������, ��������� � ������������� ���������, ����������� � ���� �����.
 *    (������ a. �������� 084)
 *
 *    @see        ����������� ���������������� �� C++.
 *    @see        ������������ ���������������� �� ��������.
 *    @see        ����� ʸ���, ������� ��. 2002.
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
      throw domain_error("������� ������� �������.");

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
      throw domain_error("������� �� ������ �� ������ ��������� ������� ");
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
   cout << "����������, ������� ���� ���: ";
   string name;
   cin >> name;
   cout << "������, " << name << "!" << endl;

   cout << "����������, ������� ������ �� ���������, "
      "����������� � �������� � ����� ��������: ";
   double midterm, fin;
   cin >> midterm >> fin;

   cout << "������� ��� ������ �� ���������� �������� �������, "
      "�������� ���� ��������� ����� �����: ";

   vector<double> homework;

   read_hw(cin, homework);

   try
   {
      double final_grade = grade(midterm, fin, homework);
      streamsize prec = cout.precision();
      cout << "���� �������� ������ ����� " << setprecision(3)
         << final_grade << setprecision(prec) << endl;
   }
   catch (domain_error)
   {
      cout << "�� ������ ������ ���� ������. "
         << "����������, ����������� �����." << endl;
      return 1;
   }

   return 0;
}

