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
 *    @brief      �������� 02. ���������� 01. �������� 057.
 *
 *    ������������� ��������� ������ ����������� � ������� ����� �������, �����
 *    ��� �������� �������, �������� ����������� � �����������.
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

#include <iostream>
#include <string>

// ���������� �� ������������� ���� ����������� ����������.
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
   setlocale(LC_ALL, "Russian");

   // ����������� ��� ��������.
   cout << "�������, ����������, ���� ���: ";

   // ������ ��������� ���.
   string name;
   cin >> name;

   // ������� ���������, ���������� ������.
   const string greeting = "������, " + name + "!";

   // ���������� ��������, ���������� �����������.
   const int pad = 0;

   // ���������� ��������� ����� � ��������.
   const int rows = pad * 2 + 3;
   const string::size_type cols = greeting.size() + pad * 2 + 2;

   // ������� ������ ������, ����� �������� ����� �� �����.
   cout << endl;

   // ������� rows �����.
   // ���������: ���� �� ������ r �����.
   for (int r = 0; r != rows; ++r)
   {
      string::size_type c = 0;

      // ���������: ���� �� ������ c �������� � ������� ������.
      while (c != cols)
      {
         // ���� �������� ����������� (greeting)?
         if (r == pad + 1 && c == pad + 1)
         {
            cout << greeting;
            c += greeting.size();
         }
         else
         {
            // �� ������ �������� �����?
            if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
            {
               cout << "*";
            }
            else
            {
               cout << " ";
            }
            ++c;
         }
      }

      cout << endl;
   }

   return 0;
}
