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
 *    @brief      �������� 01. ���������� 03. �������� 036.
 *    
 *    ��������� �� ��������� ���������? ���� ��, �� ��� ��� ������? ���� ���, ��
 *    ������?
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

   { const std::string s = "���� ������";
     std::cout << s << std::endl; }

   { const std::string s = "������ ������";
   std::cout << s << std::endl; }

   return 0;
}