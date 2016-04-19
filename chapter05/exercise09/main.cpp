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
 *    @brief      Параграф 05. Упражнение 09. Страница 128.
 *
 *    Напишите программу для вывода слов (из введенных данных) строчными буква-
 *    ми, а после них - тех же слов прописными буквами.
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
 
 #include <fstream>
 #include <iostream>
 #include <cctype>
 #include <string>
 #include <vector>
  
 using std::cin;
 using std::cout;
 using std::endl;
 using std::string;
 using std::vector;
 using std::ifstream;
 using std::getline;
 using std::isupper;
 using std::islower;
 using std::toupper;
 using std::tolower;
 
 typedef vector<string> vectorString;
 
 void getUpper(string& s)
 {
     for (string::size_type i=0; i<s.size(); i++)
     {
         if (islower(s[i])) s[i] = toupper(s[i]);
     }
 }
 
 void getLower(string& s)
 {
     for (string::size_type i=0; i<s.size(); i++)
     {
         if (isupper(s[i])) s[i] = tolower(s[i]);
     }
 }
 
 int main()
 {
     ifstream in("input.txt");
     vectorString l, u;
     string s;
     
     while(getline(in,s))
     {
         getLower(s);
         l.push_back(s);
         getUpper(s);
         u.push_back(s);
     }
     
     for (vectorString::size_type i=0; i<l.size();i++) cout<<l[i]<<endl;
     for (vectorString::size_type i=0; i<u.size();i++) cout<<u[i]<<endl;
     
     return 0;
 }