/******************************************************************************
 *       Project: AcceleratedCPP
 * (c) Copyright: 2014
 *       Company: Home
 *                All rights reserved
 * Secrecy Level: PUBLIC
 *****************************************************************************/

/**
 *    @file       main.cpp
 *    @author     VShylienkov
 *    @brief      Параграф 07. Упражнение 02. Страница 169.
 *    
 *    Дополните программу, приведенную в разделе 4.2.3, чтобы она присваивала
 *    буквенные обозначения различным уровням успеваемости студентов по следу-
 *    ющим диапазонам.
 * 
 *    A     90-100
 *    B     80-89.99
 *    C     70-79.99
 *    D     60-69.99
 *    F     < 60
 * 
 *    В результатах должно быть указано количество студентов каждой категории.
 *
 *    @see        Эффективное программирование на C++.
 *    @see        Практическое программирование на примерах.
 *    @see        Эндрю Кёниг, Барбара Му. 2002.
 */

/**
 *   Version history:
 *
 *   2014-12-29   0.1.0   VShilenkov   Initial
 */

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

#include "Student_info.hpp"
#include "grade.hpp"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::ifstream;
using std::map;
using std::max;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

char map_grade(double grade)
{
    char r{'F'};

    if (grade >= 90)
        r = 'A';
    else if (grade >= 80)
        r = 'B';
    else if (grade >= 70)
        r = 'C';
    else if (grade >= 60)
        r = 'D';

    return r;
}

int main( )
{
    vector<Student_info> students;
    Student_info         record;
    string::size_type    maxlen = 0;
    ifstream             in("input10000.txt");

    while (read(in, record))
    {
        maxlen = max(maxlen, record.name.size( ));
        students.push_back(record);
    }

    sort(students.begin( ), students.end( ), compare);
    map<char, unsigned int> statistics;

    for (vector<Student_info>::size_type i = 0; i != students.size( ); i++)
    {
        cout << students[i].name << string(maxlen - students[i].name.size( ) + 1, ' ');
        try
        {
            double     final_grade = grade(students[i]);
            streamsize prec        = cout.precision( );
            char c = map_grade(final_grade);
            cout << setprecision(3) << final_grade << '\t' << c;
            cout.precision(prec);
            ++statistics[c];
        }
        catch (domain_error e)
        {
            cout << e.what( );
        }
        cout << endl;
    }

    for(const auto& mark : statistics)
    {
        cout << mark.first << '\t' << mark.second << '\n';
    }

    return 0;
}
