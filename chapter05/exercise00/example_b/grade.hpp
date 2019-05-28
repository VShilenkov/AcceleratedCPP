#ifndef GUARD_GRADE_HPP
#define GUARD_GRADE_HPP

#include "Student_info.hpp"

mark_t grade(mark_t midterm, mark_t fin, mark_t homework);
mark_t grade(mark_t midterm, mark_t fin, const mark_cnt_t& hw);
mark_t grade(const Student_info& s);

#endif    // !GUARD_GRADE_HPP
