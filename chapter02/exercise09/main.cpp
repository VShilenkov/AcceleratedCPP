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
 *    @brief      �������� 02. ���������� 09. �������� 058.
 *    
 *    �������� ���������, ������� �� ���������� ������������ ������ ��� �����, �
 *    ����� ��������, ����� �� ��� ������.
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

int main()
{
   setlocale(LC_ALL, "Russian");
   std::cout << "������� ��� �����: ";
   int a, b;
   std::cin >> a >> b;

   if (a == b) std::cout << "����� �����!"; 
   else        std::cout << "����� " << ((a > b) ? a : b) << " �������";

   return 0;
}
