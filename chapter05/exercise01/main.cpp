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
 *    @brief      Параграф 05. Упражнение 01. Страница 127.
 *
 *    Продумайте и напишите программу для получения перестановочного индекса.
 *    Перестановочный индекс - это индекс, в котором каждая фраза индексируется
 *    каждым ее словом. Например, при таких входных данных
 *
 *    The quick brown fox
 *    jumped over the fence
 *    
 *    результат должен быть следующим.
 *
 *          The quick   brown fox
 *    jumped over the   fence
 *    The quick brown   fox
 *                      jumped over the fence
 *             jumped   over the fence
 *                The   quick brown fox
 *        jumped over   the fence
 *                      The quick brown fox
 *    
 *    Неплохой алгоритм предлагается в книге Ахо (Aho), Кернигана (Kernighan) и
 *    Вейнбергера (Weinberger) The AWK Programming Language (Addision-Wesley, 1988)
 *    Проблема делится на три этапа.
 *    1. Читаем каждую строку входных данных и генерируем набор циклически сдвинутых
 *       фраз этой строки. При каждом циклическом сдвиге следующее слово из исходных
 *       данных перемещается в первую позицию, а предыдущее первое слово перемещается
 *       в конец фразы. Вот как выглядит результат циклического сдвига фразы из первой
 *       строки наших исходных данных.
 *
 *    The quick brown fox
 *    quick brown fox The
 *    brown fox The quick
 *    fox The quick brown
 *    
 *    Конечно же, важно знать, где оканчивается исходная фраза и где находится начало
 *    циклически сдвинутой фразы.
 *    2. Сортируем циклически сдвинутые фразы.
 *    3. Отменяем циклический сдвиг и записываем перестановочный индекс, что означает
 *       отыскать разделитель, поместить фразу на место и записать ее в отформатирован-
 *       отформатированном виде.
 *
 *    @see        Эффективное программирование на C++.
 *    @see        Практическое программирование на примерах.
 *    @see        Эндрю Кёниг, Барбара Му. 2002.
 */
 
/**
 *   Version history:
 *
 *   2015-01-14   0.1.0   VShilenkov   Initial
 */

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::sort;
using std::ifstream;
using std::isspace;
using std::string;
using std::vector;

typedef string::size_type        string_size;
typedef vector<string>           string_vector;
typedef string_vector::size_type string_vector_size;

string_vector split(const string& s)
{
   string_vector ret;
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

string::size_type find(const string& s, const char& c)
{
   string_size ret = s.size();
   for (string_size i = ret; i != 0; i--)
   {
      if (s[i - 1] == c)
      {
         ret = i - 1;
         break;
      }
   }

   return ret;
}

int main()
{
   string s;
   ifstream in("input.txt");
   
   

   string_vector permutation_index;

   string::size_type left_col_width = 0;

   while (getline(in, s))
   {
      string_vector words = split(s);
      string_vector_size words_size = words.size();

      words[words_size - 1] += "|";

      string::size_type current_width = 0;

      for (string_vector_size i = 0; i != words_size; i++)
      {
         if (i != words_size - 1) current_width += words[i].size();

         string cyclic_string = "";
         for (string_vector_size j = i; j != words_size + i; j++)
         {
            cyclic_string += words[j % words_size] + " ";
         }
         permutation_index.push_back(cyclic_string.substr(0, cyclic_string.size() - 1));
      }

      if (current_width + words.size() - 2 > left_col_width) left_col_width = current_width + words.size() - 2;
   }

   sort(permutation_index.begin(), permutation_index.end());

   for (string_vector_size i = 0; i != permutation_index.size(); i++)
   {
      s = permutation_index[i];
      string_size delimetr_index = find(s, '|');
      string_size real_string_size = s.size() - 1;
      string delimetr = "\t";


      if (delimetr_index == real_string_size)
      {
         cout << string(left_col_width, ' ') << delimetr << s.substr(0, delimetr_index) << endl;
      }
      else if (left_col_width + delimetr_index == real_string_size - 1)
      {
         cout << s.substr(delimetr_index + 2, real_string_size - delimetr_index)
              << delimetr << s.substr(0, delimetr_index) << endl;
      }
      else
      {
         cout << string(left_col_width + delimetr_index - real_string_size + 1, ' ')
              << s.substr(delimetr_index + 2, real_string_size - delimetr_index)
              << delimetr << s.substr(0, delimetr_index) << endl;
      }
   }

   return 0;
}