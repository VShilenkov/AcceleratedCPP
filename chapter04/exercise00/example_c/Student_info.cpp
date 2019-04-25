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

using std::istream;
using std::vector;

bool compare(const Student_info& x, const Student_info& y)
{
   return x.name < y.name;
}

istream& read(std::istream& in, Student_info& s)
{
   in >> s.name >> s.midterm >> s.fin;

   read_hw(in, s.homework);

   return in;
}

istream& read_hw(std::istream& in, std::vector<double>& hw)
{
   if (in)
   {
      hw.clear();

      double x;
      while (in >> x)
         hw.push_back(x);

      in.clear();
   }
   return in;
}
