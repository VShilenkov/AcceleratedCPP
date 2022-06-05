/******************************************************************************
 *       Project: AcceleratedCPP
 * (c) Copyright: 2015
 *       Company: Home
 *                All rights reserved
 * Secrecy Level: PUBLIC
 *****************************************************************************/

/**
 *    @file       main.cpp
 *    @author     VShylienkov
 *    @brief      Параграф 06. Упражнение 01. Страница 151.
 *
 *    Перепишите реализацию функций frame и hcat из разделов 5.8.1 и 5.8.3, чтобы
 *    в них использовались итераторы.
 *
 *    @see        Эффективное программирование на C++.
 *    @see        Практическое программирование на примерах.
 *    @see        Эндрю Кёниг, Барбара Му. 2002.
 */

/**
 *   Version history:
 *
 *   2022-06-05   0.1.0   VShylienkov   Initial
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

string::size_type width(const vector<string> &v)
{
    auto m = std::max_element(v.begin( ), v.end( ), [](const std::string &l, const std::string &r) {
        return l.length( ) < r.length( );
    });
    return m != v.end( ) ? m->length( ) : 0;
}

vector<string> frame(const vector<string> &v)
{
    vector<string>    ret;
    string::size_type maxlen = width(v);
    string            border(maxlen + 4, '*');

    ret.push_back(border);

    for (auto i = v.begin( ); i != v.end( ); ++i)
    {
        ret.push_back("* " + *i + string(maxlen - i->size( ), ' ') + " *");
    }

    ret.push_back(border);

    return ret;
}

vector<string> hcat(const vector<string> &left, const vector<string> &right)
{
   vector<string> ret;

   string::size_type width1 = width(left) + 1;

   auto i = left.begin(), j = right.begin();

   while (i != left.end() || j != right.end())
   {
      string s;

      if (i != left.end())
         s = *i++;

      s += string(width1 - s.size(), ' ');

      if (j != right.end())
         s += *j++;

      ret.push_back(s);
   }

   return ret;
}

int main( )
{
    string         s;
    vector<string> v;
    while (cin >> s)
    {
        v.push_back(s);
    }

    vector<string> b = hcat(v, frame(v));

    cout << endl;

    for (vector<string>::iterator i = b.begin( ); i != b.end( ); i++)
    {
        cout << *i << endl;
    }

    return 0;
}