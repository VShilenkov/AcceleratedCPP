/******************************************************************************
 *       Project: AcceleratedCPP
 * (c) Copyright: 2015
 *       Company: Home
 *                All rights reserved
 * Secrecy Level: PUBLIC
 *****************************************************************************/

/**
 *    @file       main.cpp
 *    @author     VShilenkov
 *    @brief      �������� 05. ���������� 00. �������� 127.
 *
 *    �������������, ��������� � ������������� ���������, ����������� � ���� �����.
 *    (������ e. �������� 115)
 *
 *    @see        ����������� ���������������� �� C++.
 *    @see        ������������ ���������������� �� ��������.
 *    @see        ����� ʸ���, ������� ��. 2002.
 */
 
/**
 *   Version history:
 *
 *   2015-01-12   0.1.0   VShilenkov   Initial
 */

#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

 using std::cin;
 using std::cout;
 using std::endl;
 using std::getline;
 using std::ifstream;
 using std::isspace;
 using std::string;
 using std::vector;

 vector<string> split(const string& s)
 {
    vector<string> ret;
    typedef string::size_type string_size;
    string_size i = 0;

    while (i != s.size())
    {
       while (i != s.size() && isspace(s[i]))
       {
          ++i;
       }

       string_size j = i;

       while (j != s.size() && !isspace(s[j]))
       {
          ++j;
       }

       if (i != j)
       {
          ret.push_back(s.substr(i, j - i));
          i = j;
       }
    }

    return ret;
 }

 int main()
 {
    string s;
    ifstream in("input.txt");

    while (getline(in, s))
    {
       vector<string> v = split(s);

       for (vector<string>::size_type i = 0; i != v.size(); i++)
       {
          cout << v[i] << endl;
       }
    }
 }

