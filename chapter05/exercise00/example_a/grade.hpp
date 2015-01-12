#ifndef GUARD_grade_hpp
#define GUARD_grade_hpp

#include <vector>
#include "Student_info.hpp"

double grade(double midterm, double fin, double homework);
double grade(double midterm, double fin, const std::vector<double>& hw);
double grade(const Student_info& s);

#endif // !GUARD_grade_hpp
