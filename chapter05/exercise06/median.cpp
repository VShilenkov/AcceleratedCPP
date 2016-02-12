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

#include <algorithm>
#include <stdexcept>

#include "median.hpp"

using std::sort;
using std::vector;
using std::domain_error;

double median(vector<double> vec)
{
   typedef vector<double>::size_type vec_sz;

   vec_sz size = vec.size();
   if (size == 0)
      throw domain_error("Медиана пустого вектора.");

   sort(vec.begin(), vec.end());
   vec_sz mid = size / 2;

   return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

