/******************************************************************************
 *       Project: AcceleratedCPP
 * (c) Copyright: 2014
 *       Company: Home
 *                All rights reserved
 * Secrecy Level: PUBLIC
 *****************************************************************************/

/**
 *    @file       grade.cpp
 *    @author     VShilenkov
 *    @brief      Calculating students grade on a special politics.
 *
 *    @see
 */

/**
 *   Version history:
 *
 *   2014-12-29   0.1.0   VShilenkov   Initial
 */

#include "Student_info.hpp"
#include "grade.hpp"
#include "median.hpp"

#include <stdexcept>
#include <vector>

using std::domain_error;
using std::vector;

double grade(double midterm, double fin, double homework)
{
    return 0.2 * midterm + 0.4 * fin + 0.4 * homework;
}

double grade(double midterm, double fin, const vector<double>& hw)
{
    if (hw.size( ) == 0)
        throw domain_error("Студент не сделал ни одного домашнего задания ");
    return grade(midterm, fin, median(hw));
}

double grade(const Student_info& s)
{
    return grade(s.midterm, s.fin, s.homework);
}
