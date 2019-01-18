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
 *    @brief      �������� 01. ���������� 05. �������� 037.
 *
 *    ��������� �� ����� ���������? ���� ��, �� ��� ��� ������? ���� ���, �� ��������,
 *    ������, � ���������� ���������� �������.
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
   { std::string s = "���� ������";
   { std::string x = s + ", �������������";
     std::cout << s << std::endl; //}
     std::cout << x << std::endl; }
   }
   return 0;
}


// main.cpp: In function 'int main()' :
// main.cpp : 37 : 19 : error : 'x' was not declared in this scope
// std::cout << x << std::endl;
//              ^