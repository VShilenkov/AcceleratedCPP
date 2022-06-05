/******************************************************************************
 *       Project: AcceleratedCPP
 * (c) Copyright: 2014
 *       Company: Home
 *                All rights reserved
 * Secrecy Level: PUBLIC
 *****************************************************************************/

/**
 *    @file       average.cpp
 *    @author     VShylienkov
 *    @brief      average of vector of doubles.
 *
 *    @see
 */

/**
 *   Version history:
 *
 *   2022-06-25   0.1.0   VShylienkov   Initial
 */

#include <numeric>
#include <stdexcept>

#include "median.hpp"

using std::domain_error;
using std::vector;

double average(const vector<double> &vec)
{
    typedef vector<double>::size_type vec_sz;

    vec_sz size = vec.size( );
    if (size == 0)
        throw domain_error("Среднее пустого вектора.");

    return std::accumulate(vec.begin( ), vec.end( ), 0.0) / size;
}
