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
 *    @brief      �������� 04. ���������� 02. �������� 099.
 *
 *    �������� ��������� ���������� ��������� int-�������� �� 100. ��� ���������
 *    ������ ������� ��� �������: � ������ ������ ���� ��������, � �� ������ - �������
 *    ����� ��������. ��� ���������� ������� ������, �.�. ����� ��������� ��������
 *    ���� ��������� �� ��������, ����������� ������� setw().
 *
 *    @see        ����������� ���������������� �� C++.
 *    @see        ������������ ���������������� �� ��������.
 *    @see        ����� ʸ���, ������� ��. 2002.
 */
 
/**
 *   Version history:
 *
 *   2014-12-29   0.1.0   VShilenkov   Initial
 */

#include <iomanip>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::streamsize;

int main()
{
   const int up_bound = 100;
   streamsize maxlen = 0;

   int t = up_bound;
   while (t > 0)
   {
      t /= 10;
      maxlen++;
   }
   

   for (int i = 0; i < up_bound; i++)
   {
      cout << setw(maxlen) << i << setw(2 * maxlen - 1) << i*i << endl;
   }

   return 0;
}