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
 *    @brief      �������� 02. ���������� 10. �������� 058.
 *    
 *    �������� ������ �� ���������� �������� std:: � ��������� ���������.
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
   int k = 0;
   int n = 10;
   while (k != n)
   {
      // ���������: ���� �� ������
      // k �������� "���������"
      using std::cout;
      cout << "*";
      ++k;
   }
   std::cout << std::endl; // ����� ����� ������� std::.
   return 0;

}
