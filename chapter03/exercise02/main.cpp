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
 *    @brief      �������� 03. ���������� 01. �������� 074.
 *
 *    �������� ���������, ������� ������ ���������, ������� ��� ������ ��������� 
 *    ����� ���������� �� ��������� ������.
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

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::string;
using std::vector;

int main()
{
   vector<string> words;

   string word;

   while (cin >> word)
   {
      words.push_back(word);
   }

   sort(words.begin(), words.end());

   typedef vector<string>::iterator vec_string_i;

   word = *words.begin();
   size_t count = 0;
   for (vec_string_i i = words.begin(); i != words.end(); i++)
   {
      if (word != *i)
      {
         cout << word << "\t" << count << endl;
         word = *i;
         count = 1;
      }
      else
      {
         count++;
      }
   }
   cout << word << count << endl;

   return 0;
}
