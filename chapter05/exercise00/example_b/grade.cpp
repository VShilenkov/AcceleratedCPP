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

#include "grade.hpp"
#include "median.hpp"

#include <stdexcept>

mark_t grade(mark_t midterm, mark_t fin, mark_t homework)
{
    return .2 * midterm + .4 * fin + .4 * homework;
}

mark_t grade(mark_t midterm, mark_t fin, const mark_cnt_t& hw)
{
    if (hw.empty( ))
        throw std::domain_error("Студент не сделал ни одного домашнего задания ");
    return grade(midterm, fin, median(hw));
}

mark_t grade(const Student_info& s)
{
    return grade(s.midterm, s.fin, s.homework);
}
