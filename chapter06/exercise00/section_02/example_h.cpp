/******************************************************************************
 *       Project: AcceleratedCPP
 * (c) Copyright: 2022
 *       Company: Home
 *                All rights reserved
 * Secrecy Level: PUBLIC
 *****************************************************************************/

/**
 *    @file       example_h.cpp
 *    @author     VShilenkov
 *    @brief      Параграф 06. Упражнение 00. Страница 151.
 *
 *    Скомпилируйте, выполните и протестируйте программы, приведенные в этой главе.
 *    (Пример h. Страница 145)
 *
 *    @see        Эффективное программирование на C++.
 *    @see        Практическое программирование на примерах.
 *    @see        Эндрю Кёниг, Барбара Му. 2002.
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

#include "Student_info.hpp"
#include "average.hpp"
#include "grade.hpp"
#include "median.hpp"

double grade_aux(const Student_info &s)
{
    try
    {
        return grade(s);
    }
    catch (const std::domain_error &e)
    {
        return grade(s.midterm, s.fin, 0);
    }
}

double average_grade(const Student_info &s)
{
    double average_homework = 0.;
    try
    {
        average_homework = average(s.homework);
    }
    catch (const std::exception &e)
    {
        average_homework = 0.;
    }
    return grade(s.midterm, s.fin, average_homework);
}

double optimistic_median_grade(const Student_info &s)
{
    std::vector<double> nonzero;

    std::remove_copy(s.homework.begin( ), s.homework.end( ), std::back_inserter(nonzero), 0);

    if (nonzero.empty( ))
        return grade(s.midterm, s.fin, 0);
    else
        return grade(s.midterm, s.fin, median(nonzero));
}

double median_analysis(const std::vector<Student_info> &students)
{
    std::vector<double> grades;

    std::transform(students.begin( ), students.end( ), std::back_inserter(grades), grade_aux);

    return median(grades);
}

double average_analysis(const std::vector<Student_info> &students)
{
    std::vector<double> grades;

    std::transform(students.begin( ), students.end( ), std::back_inserter(grades), average_grade);

    return median(grades);
}

double optimistic_median_analysis(const std::vector<Student_info> &students)
{
    std::vector<double> grades;

    std::transform(students.begin( ), students.end( ), std::back_inserter(grades), optimistic_median_grade);

    return median(grades);
}

void write_analysis(std::ostream                    &out,
                    const std::string               &name,
                    double                           analysis(const std::vector<Student_info> &),
                    const std::vector<Student_info> &did,
                    const std::vector<Student_info> &didnt)
{
    out << name << ": median(did) = " << analysis(did) << ", median(didnt) = " << analysis(didnt) << std::endl;
}

bool did_all_hw(const Student_info &s)
{
    return (std::find(s.homework.cbegin( ), s.homework.cend( ), 0) == s.homework.cend( ));
}

int main( )
{
    // Студенты, которые выполнили и не выполнили
    // все домашние задания
    std::vector<Student_info> did, didnt;

    std::ifstream in("input.txt");

    // Читаем все записи, разделяя их по принципу выполнения
    // (и невыполнения) всех домашних заданий
    Student_info student;
    while (read(in, student))
    {
        if (did_all_hw(student))
        {
            did.push_back(student);
        }
        else
        {
            didnt.push_back(student);
        }
    }

    // Удостоверяемся, что результаты анализа существуют и нам есть что показать
    if (did.empty( ))
    {
        std::cout << "Ни один студент не выполнил всех домашних заданий!" << std::endl;
        return 1;
    }

    if (didnt.empty( ))
    {
        std::cout << "Все студенты выполнили все домашние задания!" << std::endl;
        return 1;
    }

    // Выполнение всех видов анализа
    write_analysis(std::cout, "median", median_analysis, did, didnt);
    write_analysis(std::cout, "average", average_analysis, did, didnt);
    write_analysis(std::cout, "median of homework turned in", optimistic_median_analysis, did, didnt);

    return 0;
}