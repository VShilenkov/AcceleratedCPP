/******************************************************************************
 *       Project: AcceleratedCPP
 * (c) Copyright: 2022
 *       Company: Home
 *                All rights reserved
 * Secrecy Level: PUBLIC
 *****************************************************************************/

/**
 *    @file       example_j.cpp
 *    @author     VShilenkov
 *    @brief      Параграф 06. Упражнение 00. Страница 151.
 *
 *    Скомпилируйте, выполните и протестируйте программы, приведенные в этой главе.
 *    (Пример j. Страница 148)
 *
 *    @see        Эффективное программирование на C++.
 *    @see        Практическое программирование на примерах.
 *    @see        Эндрю Кёниг, Барбара Му. 2002.
 */

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "Student_info.hpp"
#include "grade.hpp"

bool fgrade(const Student_info &s)
{
    return grade(s) < 60;
}

bool pgrade(const Student_info &s)
{
    return !fgrade(s);
}

std::vector<Student_info> extract_fails(std::vector<Student_info> &students)
{
    std::vector<Student_info>::iterator iter = std::stable_partition(students.begin( ), students.end( ), pgrade);
    std::vector<Student_info>           fail(iter, students.end( ));
    students.erase(iter, students.end( ));
    return fail;
}

int main( )
{
    std::vector<Student_info> students, fail;
    Student_info              record;
    std::string::size_type    maxlen = 0;

    std::ifstream in("input.txt");

    while (read(in, record))
    {
        maxlen = std::max(maxlen, record.name.size( ));
        students.push_back(record);
    }

    fail = extract_fails(students);

    for (std::vector<Student_info>::size_type i = 0; i != students.size( ); i++)
    {
        std::cout << students[i].name << std::string(maxlen - students[i].name.size( ) + 1, ' ');
        try
        {
            double          final_grade = grade(students[i]);
            std::streamsize prec        = std::cout.precision( );
            std::cout << std::setprecision(3) << final_grade << std::setprecision(prec);
        }
        catch (std::domain_error e)
        {
            std::cout << e.what( );
        }
        std::cout << std::endl;
    }

    return 0;
}