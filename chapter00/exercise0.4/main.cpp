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
 *    @brief      �������� 00. ���������� 04. �������� 027.
 *    
 *    �������� ���������, ������� ������� ����� ���������, ��������� �����
 *    "������, ���!".
 *
 *    @see        ����������� ���������������� �� C++.
 *    @see        ������������ ���������������� �� ��������.
 *    @see        ����� ʸ���, ������� ��. 2002.
 */
 
/**
 *   Version history:
 *
 *   2014-12-23   0.1.0   VShilenkov   Initial
 */

#include <iostream>

int main()
{
   setlocale(LC_ALL, "Russian");

   std::cout << "#include <iostream>\n\n";
   std::cout << "int main()\n{\n";
   std::cout << "\tsetlocale(LC_ALL, \"Russian\");\n\n";
   std::cout << "\tstd::cout << \"������, ���!\";\n\n";
   std::cout << "\treturn 0;\n}";

   return 0;
}