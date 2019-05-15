/******************************************************************************
 *       Project: AcceleratedCPP
 * (c) Copyright: 2014
 *       Company: Home
 *                All rights reserved
 * Secrecy Level: PUBLIC
 *****************************************************************************/

/**
 *    @file       main.cpp
 *    @author     VShilenkov
 *    @brief      Параграф 04. Упражнение 06. Страница 099.
 *
 *    Перепишите структуру Student_info для немедленного вычисления оценок и
 *    сохранения значения только итоговой оценки.
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

#include "numeric.hpp"

#include <iostream>

typedef double              mark_t;
typedef std::vector<mark_t> marks_container_t;

std::istream& operator>>(std::istream&, marks_container_t&);

struct Student_info
{
    std::string name;
    mark_t      final_grade;
};

std::istream& operator>>(std::istream&, Student_info&);

inline bool operator<(const Student_info& lhs, const Student_info& rhs)
{
    return lhs.name < rhs.name;
}

inline mark_t median(marks_container_t marks)
{
    if (marks.empty( ))
    {
        throw std::domain_error("Медиана пустого вектора.");
    }

    return vsh::median(marks.cbegin( ), marks.cend( ), .0);
}

inline mark_t grade(const mark_t& midterm, const mark_t& fin, const mark_t& homework)
{
    return .2 * midterm + .4 * fin + .4 * homework;
}

inline mark_t grade(const mark_t& midterm, const mark_t& fin, const marks_container_t& hw)
{
    if (hw.empty( ))
    {
        throw std::domain_error("Студент не сделал ни одного домашнего задания ");
    }
    return grade(midterm, fin, median(hw));
}

std::istream& operator>>(std::istream& in, marks_container_t& hw)
{
    if (in)
    {
        hw.clear( );
        marks_container_t::value_type x;
        while (in >> x)
        {
            hw.push_back(x);
        }
        in.clear( );
    }
    return in;
}

std::istream& operator>>(std::istream& in, Student_info& s)
{
    mark_t            midterm, fin;
    marks_container_t homework;
    in >> s.name >> midterm >> fin >> homework;
    s.final_grade = (in) ? grade(midterm, fin, homework) : .0;
    return in;
}

int main( )
{
    std::vector<Student_info> students;
    Student_info              record;
    std::string::size_type    maxlen = 0;

    while (std::cin >> record)
    {
        maxlen = std::max(maxlen, record.name.size( ));
        students.push_back(record);
    }

    std::sort(students.begin( ), students.end( ));

    for (std::vector<Student_info>::iterator student(students.begin( )); student != students.end( ); ++student)
    {
        using std::cout;
        cout << student->name << std::string(maxlen + 1U - student->name.size( ), ' ');

        try
        {
            mark_t          final_grade = student->final_grade;
            std::streamsize precision   = cout.precision(3);
            cout << final_grade;
            cout.precision(precision);
        }
        catch (std::domain_error e)
        {
            cout << e.what( );
        }

        cout << std::endl;
    }
}
