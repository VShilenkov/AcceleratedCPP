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
 *    @brief      �������� 01. ���������� 02. �������� 036.
 *
 *    ��������� �� ����� �����������? ������?
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

#include <string>

int main() 
{ 
   const std::string excalm = "!";
   const std::string message = "������" + ", ���" + excalm;

   return 0;
}

// main.cpp: In function 'int main()':
// main.cpp:32 : 43 : error : invalid operands of types 'const char [7]' and 'const char [6]' to binary 'operator+'
// const std::string message = "������" + ", ���" + excalm;
//                                        ^
