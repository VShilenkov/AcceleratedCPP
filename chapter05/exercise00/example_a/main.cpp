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
 *    @brief      Параграф 05. Упражнение 00. Страница 127.
 *
 *    Скомпилируйте, выполните и протестируйте программы, приведенные в этой главе.
 *    (Пример a. Страница 102)
 *
 *    @see        Эффективное программирование на C++.
 *    @see        Практическое программирование на примерах.
 *    @see        Эндрю Кёниг, Барбара Му. 2002.
 */

/**
 *   Version history:
 *
 *   2015-01-12   0.1.0   VShilenkov   Initial
 */

#include "Student_info.hpp"
#include "grade.hpp"

#include <fstream>
#include <iostream>

inline bool fgrade(const Student_info& s)
{
    return grade(s) < 60;
}

typedef std::vector<Student_info> student_cnt_t;

student_cnt_t extract_fails(student_cnt_t&);

int main( )
{
    student_cnt_t          students, fail;
    Student_info           record;
    std::string::size_type maxlen = 0;

    std::ifstream in("input.txt");

    while (in >> record)
    {
        maxlen = std::max(maxlen, record.name.size( ));
        students.push_back(record);
    }

    fail = extract_fails(students);

    for (student_cnt_t::size_type i = 0; i != students.size( ); i++)
    {
        std::cout << students[i].name << std::string(maxlen - students[i].name.size( ) + 1, ' ');
        try
        {
            mark_t          final_grade = grade(students[i]);
            std::streamsize prec        = std::cout.precision(3);
            std::cout << final_grade;
            std::cout.precision(prec);
        }
        catch (std::domain_error e)
        {
            std::cout << e.what( );
        }
        std::cout << std::endl;
    }

    return 0;
}

std::vector<Student_info> extract_fails(std::vector<Student_info>& students)
{
    std::vector<Student_info> pass, fail;

    for (std::vector<Student_info>::size_type i = 0; i != students.size( ); ++i)
    {
        if (fgrade(students[i]))
            fail.push_back(students[i]);
        else
            pass.push_back(students[i]);
    }
    students = pass;
    return fail;
}
