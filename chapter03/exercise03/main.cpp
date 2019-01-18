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
 *    @brief      �������� 03. ���������� 03. �������� 074.
 *    
 *    �������� ��������� ��� ������ ����� ������ �������� � ������ ��������� 
 *    string-�������� �� ��������� ������.
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

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
   string word;

   if (cin >> word)
   {
      string longestWord(word);
      string shortestWord(word);

      while (cin >> word)
      {
         if (word.size() > longestWord.size()) longestWord = word;
         if (word.size() < shortestWord.size()) shortestWord = word;
      }

      cout << "����� ������� �����: " << longestWord << ". ��� �����: " << longestWord.size() << endl;
      cout << "����� �������� �����: " << shortestWord << ". ��� �����: " << shortestWord.size() << endl;
   }
   else
   {
      cout << "�� ������� �� ������� �����.";
      return 1;
   }

   return 0;
}
