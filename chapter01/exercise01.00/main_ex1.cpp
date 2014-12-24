/******************************************************************************
*       Project: AcceleratedCPP
* (c) Copyright: 2014
*       Company: Home
*                All rights reserved
* Secrecy Level: PUBLIC
*****************************************************************************/

/**
*    @file       main_ex1.cpp
*    @author     VShilenkov
*    @brief      �������� 01. ���������� 00. �������� 036.
*
*    �������������, ��������� � ������������� ���������, ������������� � ����
*    �����. (������ 01. �������� 032)
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

// ����������� ��� ������������ �
// ���������� ����������� � �������.
#include <iostream>
#include <string>

int main()
{
   setlocale(LC_ALL, "Russian");

   std::cout << "�������, ����������, ���� ���: ";
   std::string name;
   std::cin >> name;

   // ������� ���������, ���������� ������.
   const std::string greeting = "������, " + name + "!";

   // ������� ������ � ��������� ������ �����������.
   const std::string spaces(greeting.size(), ' ');
   const std::string second = "* " + spaces + " *";

   // ������� ������ � ����� ������ �����������.
   const std::string first(second.size(), '*');

   // ������� ��� ������.
   std::cout << std::endl;
   std::cout << first << std::endl;
   std::cout << second << std::endl;
   std::cout << "* " << greeting << " *" << std::endl;
   std::cout << second << std::endl;
   std::cout << first << std::endl;

   return 0;
}