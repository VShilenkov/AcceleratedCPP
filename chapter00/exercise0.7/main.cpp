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
 *    @brief      �������� 00. ���������� 07. �������� 028.
 *
 *    � ��� �� ������� �� ���� ���������?
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
/* ���� ���������� ����� �������� ��������� �����, ���������
� �������� ���������� � ��������� ������������� �� ����������
������� /* � */. */
std::cout << "���� ������� ��������� ����� ��������?" << std::endl;
return 0;
}

//main.cpp: In function 'int main()':
//main.cpp:32 : 16 : error : expected primary - expression before '.' token
//������� /* � */. * /
//               ^
//main.cpp : 32 : 18 : error : expected unqualified - id before '*' token
//������� /* � */. * /
//                 ^
//main.cpp : 32 : 19 : error : expected primary - expression before '/' token
//������� /* � */. * /
//                   ^