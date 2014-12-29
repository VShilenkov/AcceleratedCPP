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
 *    @brief      �������� 04. ���������� 05. �������� 099.
 *
 *    �������� �������, ������� ��������� ����� �� �������� ������ � ��������� ��
 *    � �������. ����������� ��� ������� ��� ��������� ��������, ������� ������-
 *    ������ ���������� ���� �� ������� ������, � ����� ���������, ������� ���
 *    ����������� � ��� ������ �����.
 *
 *    @see        ����������� ���������������� �� C++.
 *    @see        ������������ ���������������� �� ��������.
 *    @see        ����� ʸ���, ������� ��. 2002.
 */
 
/**
 *   Version history:
 *
 *   2014-12-29   0.1.0   VShilenkov   Initial
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::istream;
using std::string;
using std::vector;

istream& read(istream& in, vector<string>& vec)
{
   if (in)
   {
      vec.clear();

      string word;
      while (in >> word)
      {
         vec.push_back(word);
      }

      in.clear();
   }

   return in;
}

int main()
{
   vector<string> words;
   read(cin, words);

   if (words.size() > 0)
   {
      sort(words.begin(), words.end());

      typedef vector<string>::iterator vec_string_i;

      string word = *words.begin();
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

      cout << "Total words: " << words.size() << endl;
   }

   return 0;
}