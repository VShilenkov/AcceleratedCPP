/******************************************************************************
 *       Project: AcceleratedCPP
 * (c) Copyright: 2014
 *       Company: Home
 *                All rights reserved
 * Secrecy Level: PUBLIC
 *****************************************************************************/

/**
 *    @file       median.cpp
 *    @author     VShilenkov
 *    @brief      median of vector of doubles.
 *
 *    @see
 */

/**
 *   Version history:
 *
 *   2014-12-29   0.1.0   VShilenkov   Initial
 */

#include <stdexcept>

#include "median.hpp"
#include "numeric.hpp"

double median(std::vector<double> vec)
{
    if (vec.empty( ))
    {
        throw std::domain_error("Медиана пустого вектора.");
    }

    return vsh::median(vec.cbegin( ), vec.cend( ), .0);
}
