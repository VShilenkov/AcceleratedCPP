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
 *    (������ g. �������� 121)
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

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::string;
using std::vector;

string::size_type width(const vector<string>& v)
{
   string::size_type maxlen = 0;
   for (vector<string>::size_type i = 0; i != v.size(); ++i)
   {
      maxlen = max(maxlen, v[i].size());
   }

   return maxlen;
}

vector<string> frame(const vector<string>& v)
{
   vector<string> ret;
   string::size_type maxlen = width(v);
   string border(maxlen + 4, '*');

   ret.push_back(border);

   for (vector<string>::size_type i = 0; i != v.size(); ++i)
   {
      ret.push_back("* " + v[i] + string(maxlen - v[i].size(), ' ') + " *");
   }

   ret.push_back(border);

   return ret;
}

vector<string> vcat(const vector<string>& top,
                    const vector<string>& bottom)
{
   vector<string> ret = top;

   for (vector<string>::const_iterator i = bottom.begin(); i != bottom.end(); ++i)
   {
      ret.push_back(*i);
   }

   return ret;
}

int main()
{
   string s;
   vector<string> v;
   while (cin >> s)
   {
      v.push_back(s);
   }

   vector<string> b = vcat(frame(v), v);

   cout << endl;

   for (vector<string>::iterator i = b.begin(); i != b.end(); i++)
   {
      cout << *i << endl;
   }

   return 0;
}