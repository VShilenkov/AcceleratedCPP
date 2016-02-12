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
 *    @brief      Параграф 05. Упражнение 08. Страница 128.
 *
 *    Что произойдет в функции hcat из раздела 5.8.3, если определить объект s вне
 *    области видимости while-цикла? Перепишите и выполните эту программу для
 *    подтверждения своей гипотезы.
 *
 *    @see        Эффективное программирование на C++.
 *    @see        Практическое программирование на примерах.
 *    @see        Эндрю Кёниг, Барбара Му. 2002.
 */
 
/**
 *   Version history:
 *
 *   2016-02-12   0.1.0   VShilenkov   Initial
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

vector<string> hcat(const vector<string>& left,
                    const vector<string>& right)
{
   vector<string> ret;

   string::size_type width1 = width(left) + 1;

   vector<string>::size_type i = 0, j = 0;

   string s;

   while (i != left.size() || j != right.size())
   {
      if (i != left.size())
         s = left[i++];

      s += string(width1 - s.size(), ' ');

      if (j != right.size())
         s += right[j++];

      ret.push_back(s);
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

   vector<string> b = hcat(v, frame(v));

   cout << endl;

   for (vector<string>::iterator i = b.begin(); i != b.end(); i++)
   {
      cout << *i << endl;
   }

   return 0;
}