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
 *    @brief      �������� 01. ���������� 06. �������� 037.
 *
 *    ��� ������ ��������� ���������, ���� ��� ������� ������ ������ �� �������
 *    ��� ����� (��������, ����� ������). ����������� ��������� ��������� �� ��
 *    ����������, � ����� ��������� ���� ������������.
 *
 *    @see        ����������� ���������������� �� C++.
 *    @see        ������������ ���������������� �� ��������.
 *    @see        ����� ʸ���, ������� ��. 2002.
 */
 
/**
 *   Version history:
 *
 *   2014-12-24   0.1.0   VShilenkov   Initial
 */
 
#include <iostream>
#include <string>

int main()
{
   setlocale(LC_ALL, "Russian");

   std::cout << "��� ��� �����? ";
   std::string name;
   std::cin >> name;
   std::cout << "������, " << name
      << std::endl << "� ��� ��� �����? ";
   std::cin >> name;
   std::cout << "������, " << name
      << "; � ���� ����� ���� ������� ������������!" << std::endl;
   return 0;
}