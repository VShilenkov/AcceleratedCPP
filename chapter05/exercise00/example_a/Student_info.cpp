/******************************************************************************
 *       Project: AcceleratedCPP
 * (c) Copyright: 2014
 *       Company: Home
 *                All rights reserved
 * Secrecy Level: PUBLIC
 *****************************************************************************/

/**
 *    @file       Student_info.cpp
 *    @author     VShilenkov
 *    @brief      Student information
 *
 *    @see
 */

/**
 *   Version history:
 *
 *   2014-12-29   0.1.0   VShilenkov   Initial
 */

#include "Student_info.hpp"

#include <iostream>

inline bool operator<(const Student_info& x, const Student_info& y)
{
    return x.name < y.name;
}

std::istream& operator>>(std::istream& in, Student_info& s)
{
    in >> s.name >> s.midterm >> s.fin >> s.homework;
    return in;
}

std::istream& operator>>(std::istream& in, mark_cnt_t& hw)
{
    if (in)
    {
        hw.clear( );

        mark_cnt_t::value_type x;
        while (in >> x)
        {
            hw.push_back(x);
        }

        in.clear( );
    }
    return in;
}
