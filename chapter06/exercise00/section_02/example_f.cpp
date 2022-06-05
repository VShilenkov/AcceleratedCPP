/******************************************************************************
 *       Project: AcceleratedCPP
 * (c) Copyright: 2022
 *       Company: Home
 *                All rights reserved
 * Secrecy Level: PUBLIC
 *****************************************************************************/

/**
 *    @file       example_f.cpp
 *    @author     VShilenkov
 *    @brief      Параграф 06. Упражнение 00. Страница 151.
 *
 *    Скомпилируйте, выполните и протестируйте программы, приведенные в этой главе.
 *    (Пример f. Страница 140)
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

double median_analysis(const std::vector<Student_info> &students)
{
    std::vector<double> grades;

    std::transform(students.begin( ), students.end( ), std::back_inserter(grades), grade_aux);

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
    // write_analysis(std::cout, "average", average_analysis, did, didnt);
    // write_analysis(std::cout, "median of homework turned in", optimistic_median_analysis, did, didnt);

    return 0;
}