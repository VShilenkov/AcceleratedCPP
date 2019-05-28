#ifndef GUARD_STUDENT_INFO_HPP
#define GUARD_STUDENT_INFO_HPP

#include <iosfwd>
#include <string>
#include <vector>

typedef double              mark_t;
typedef std::vector<mark_t> mark_cnt_t;

struct Student_info
{
    std::string name;
    mark_t      midterm, fin;
    mark_cnt_t  homework;
};

inline bool   operator<(const Student_info& x, const Student_info& y);
std::istream& operator>>(std::istream& in, Student_info& s);
std::istream& operator>>(std::istream& in, mark_cnt_t& hw);

#endif    // GUARD_STUDENT_INFO_HPP
