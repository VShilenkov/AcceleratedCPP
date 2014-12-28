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
 *    (������ a. �������� 059)
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

#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;

int main()
{
   setlocale(LC_ALL, "Russian");

   // ����������� � ��������� ��� ��������.
   cout << "����������, ������� ���� ���: ";
   string name;
   cin >> name;
   cout << "������, " << name << "!" << endl;

   // ����������� � ��������� ������ �� ���������,
   // ����������� � �������� � � ����� ��������.
   cout << "����������, ������� ������ �� ��������� "
      "� �������� � � ����� ��������: ";
   double midterm, fin;
   cin >> midterm >> fin;

   // ����������� ������ �� ���������� �������� �������.
   cout << "������� ��� ������ �� ���������� �������� �������, "
      "�������� ���� ��������� ����� �����: ";

   // ���������� � ����� ������, ����������� �� ��� ���.
   int count = 0;
   double sum = 0;

   // ����������, � ������� ����������� ���������� ������.
   double x;

   // ���������:
   // �� ��������� ���� count ������, �
   // ���������� sum �������� ����� ������ count ������.
   while (cin >> x)
   {
      ++count;
      sum += x;
   }

   // ������� ���������.
   streamsize prec = cout.precision();
   cout << "���� �������� ������ ����� " << setprecision(3)
      << 0.2 * midterm + 0.4 * fin + 0.4 * sum / count
      << setprecision(prec) << endl;

   return 0;
}