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
 *    @brief      �������� 02. ���������� 02. �������� 057.
 *
 *    ������������� ��������� ������ ����������� � ������� ����� �������, �����
 *    ��� ������������ ��������� ���������� �������� ��� ��������� ����������� ��
 *    ������� ������, � ��� �� �� ������� � ������.
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
   // ����������� ��� ��������.
   cout << "�������, ����������, ���� ���: ";

   // ������ ��������� ���.
   string name;
   cin >> name;

   // ������� ���������, ���������� ������.
   const string greeting = "������, " + name + "!";

   // ���������� ��������, ���������� �����������.
   const int pad_left = 1;
   const int pad_right = 2;
   const int pad_up = 3;
   const int pad_down = 4;

   // ���������� ��������� ����� � ��������.
   const int rows = pad_down + pad_up + 3;
   const string::size_type cols = greeting.size() + pad_left + pad_right + 2;

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
         if (r == pad_up + 1 && c == pad_left + 1)
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
