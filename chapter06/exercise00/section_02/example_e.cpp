/******************************************************************************
 *       Project: AcceleratedCPP
 * (c) Copyright: 2022
 *       Company: Home
 *                All rights reserved
 * Secrecy Level: PUBLIC
 *****************************************************************************/

/**
 *    @file       example_e.cpp
 *    @author     VShilenkov
 *    @brief      Параграф 06. Упражнение 00. Страница 151.
 *
 *    Скомпилируйте, выполните и протестируйте программы, приведенные в этой главе.
 *    (Пример e. Страница 139)
 *
 *    @see        Эффективное программирование на C++.
 *    @see        Практическое программирование на примерах.
 *    @see        Эндрю Кёниг, Барбара Му. 2002.
 */

#include <algorithm>
#include <fstream>    // IWYU pragma: keep
#include <vector>

#include "Student_info.hpp"

bool did_all_hw(const Student_info &s)
{
    return (std::find(s.homework.cbegin( ), s.homework.cend( ), 0) == s.homework.cend( ));
}

int main( )
{
    std::vector<Student_info> did, didnt;
    Student_info              student;
    std::ifstream             in("input.txt");

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
}