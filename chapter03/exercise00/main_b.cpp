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
*    @brief      �������� 03. ���������� 00. �������� 074.
*
*    �������������, ��������� � ������������� ���������, ����������� � ���� �����.
*    (������ b. �������� 071)
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
   // ����������� � ������ ��� ��������.
   cout << "����������, ������� ���� ���: ";
   string name;
   cin >> name;
   cout << "������, " << name << "!" << endl;

   // ����������� � ������ ������ �� ���������,
   // ����������� � �������� � � ����� ��������.
   cout << "����������, ������� ������ �� ��������� "
      "� �������� � � ����� ��������: ";
   double midterm, fin;
   cin >> midterm >> fin;

   // ����������� ������ �� ���������� �������� �������.
   cout << "������� ��� ������ �� ���������� �������� �������, "
      "�������� ���� ��������� ����� �����: ";
   vector<double> homework;
   double x;

   // ���������: ������ homework �������� ��� ������
   // �� �������� �������, ��������� �� ��� ���
   while (cin >> x)
      homework.push_back(x);

   // ���������, ���� �� ������� ������ �� �������� �������.
   typedef vector<double>::size_type vec_sz;
   vec_sz size = homework.size();

   if (size == 0)
   {
      cout << endl << "���������� ������ ������ ��� �������. " 
         "����������, ����������� �����. " << endl;
      return 1;
   }

   // ��������� ������.
   sort(homework.begin(), homework.end());

   // ��������� ��������� ������ ������� homework.
   vec_sz mid = size / 2;
   double median;
   median = size % 2 == 0 ? (homework[mid] + homework[mid - 1]) / 2
      : homework[mid];

   // ��������� � ������� ���������.
   streamsize prec = cout.precision();
   cout << "���� �������� ������ ����� " << setprecision(3)
      << 0.2 * midterm + 0.4 * fin + 0.4 * median
      << setprecision(prec) << endl;

   return 0;

}