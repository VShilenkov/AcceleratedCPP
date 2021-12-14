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
 *    @brief      Параграф 05. Упражнение 10. Страница 128.
 *
 *    Палиндромы (перевертни) - это слова, одинаково читающиеся слева направо и 
 *    справа налево. Напишите программу для отыскания всех палиндромов в словаре.
 *    Затем найдите самый длинный палиндром. 
 *
 *    @see        Эффективное программирование на C++.
 *    @see        Практическое программирование на примерах.
 *    @see        Эндрю Кёниг, Барбара Му. 2002.
 */
 
/**
 *   Version history:
 *
 *   2016-04-19   0.1.0   VShilenkov   Initial
 */
 
 #include <fstream>         // IWYU pragma: keep 
 #include <iostream>
 #include <string>
 #include <vector>
  
 using std::cin;
 using std::cout;
 using std::endl;
 using std::string;
 using std::vector;
 using std::ifstream;
 using std::getline;
  
 typedef vector<string> vectorString;
 
 string::size_type isPalyndrom(string& s)
 {
     string::size_type length = s.size();
     for (string::size_type i = 0; i < (length / 2); i++)
     {
         if (s[i] != s[length-i-1]) return 0;
     }
     return length;
 }
 
 int main()
 {
     ifstream in("input.txt");
     vectorString p;
     string s, longest;
     string::size_type maxpl = 0;
     
     while(in.good() && !in.eof())
     {
         in >> s;
         
         string::size_type pl = isPalyndrom(s); 
         
         if (0 < pl)
         {
             if (pl > maxpl)
             {
                 maxpl = pl;
                 longest = s;
             }
             
             bool found = false;
             
             for (vectorString::size_type i = 0; i < p.size(); i++)
             {
                 if (s==p[i]) 
                 {
                     found = true;
                     break;
                 }
             }
             
             if (!found) p.push_back(s);
         }
     }
     
     for (vectorString::size_type i=0; i<p.size();i++) cout<<p[i]<<endl;
     cout << longest << " " << maxpl << endl;
          
     return 0;
 }