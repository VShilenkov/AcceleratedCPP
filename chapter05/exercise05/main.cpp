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
 *    @brief      Параграф 05. Упражнение 05. Страница 127.
 *    
 *    Напишите функцию center(const vector<string>&), возвращающую картин-
 *    ку, в которой все строки картинки дополняются пробелами до макси-
 *    мальной длины, а это дополнение пробелами по возможности поровну делится
 *	  между левой и правой сторонами картинки. Каковы свойства картинок, для ко-
 *	  торых будет полезной такая функция? Как узнать, обладает ли данная картинка
 *	  такими свойствами?
 *
 *    @see        Эффективное программирование на C++.
 *    @see        Практическое программирование на примерах.
 *    @see        Эндрю Кёниг, Барбара Му. 2002.
 */
 
/**
 *   Version history:
 *
 *   2016-02-08   0.1.0   VShilenkov   Initial
 */

 #include <vector>
 #include <string>
 #include <fstream>
 #include <iostream>

 using std::vector;
 using std::string;
 using std::max;
 using std::ifstream;
 using std::cin;
 using std::cout;
 using std::endl;
 using std::getline;

string::size_type width(const vector<string>& v)
{
	string::size_type maxlen = 0;
	for (vector<string>::size_type i=0; i != v.size(); ++i)
	{
		maxlen = max(maxlen, v[i].size());
	}

	return maxlen;
}

vector<string> center (const vector<string>& v)
{
	vector<string> result;
	string::size_type max_width=width(v);

	cout << max_width << endl;

	for (vector<string>::size_type i=0; i!=v.size(); ++i)
	{
		string::size_type tabs_width = max_width - v[i].size();
		string left_tab((tabs_width+1)/2, ' ');
		string right_tab(tabs_width/2, ' ');
		result.push_back(left_tab + v[i] + right_tab);
	}

	return result;
}

int main()
{
	ifstream in("input.txt");
	string s;
	vector<string> text, centered;

	while (getline(in,s))
	{
		text.push_back(s);
	}

	centered = center(text);

	for (vector<string>::size_type i=0; i!=centered.size(); ++i)
	{
		cout << centered[i] << endl;
	}

	return 0;
}