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
 *    (Пример b. Страница 103)
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
#include <iomanip>
//#include <ios>
#include <iostream>
//#include <stdexcept>
//#include <string>
//#include <vector>

// using std::cin;
// using std::cout;
// using std::domain_error;
// using std::endl;
// using std::ifstream;
// using std::max;
// using std::setprecision;
// using std::streamsize;
// using std::string;
// using std::vector;

inline bool fgrade(const Student_info& s)
{
    return grade(s) < 60;
}

typedef std::vector<Student_info> student_cnt_t;

student_cnt_t extract_fails(student_cnt_t& students);
void          report(std::ostream& out, const student_cnt_t& students, const int& maxlen);

int main( )
{
    student_cnt_t students, fail;
    Student_info  record;
    int           maxlen(0);

    std::ifstream in("input.txt");

    while (in >> record)
    {
        int size = static_cast<int>(record.name.size( ));
        if (size > maxlen)
        {
            maxlen = size;
        }
        students.push_back(record);
    }

    fail = extract_fails(students);

    report(std::cout, students, maxlen + 1);
    return 0;
}

student_cnt_t extract_fails(student_cnt_t& students)
{
    student_cnt_t            fail;
    student_cnt_t::size_type i = 0;

    while (i != students.size( ))
    {
        if (fgrade(students[i]))
        {
            fail.push_back(students[i]);
            student_cnt_t::const_iterator e = students.begin( );
            std::advance(e, i);
            students.erase(e);
        }
        else
        {
            ++i;
        }
    }

    return fail;
}

void report(std::ostream& out, const student_cnt_t& students, const int& maxlen)
{
    for (const Student_info& s : students)
    {
        out << std::left << std::setw(maxlen) << s.name;
        try
        {
            std::streamsize prec = out.precision(3);
            out << grade(s);
            out.precision(prec);
        }
        catch (std::domain_error e)
        {
            out << e.what( );
        }
        out << std::endl;
    }
}
