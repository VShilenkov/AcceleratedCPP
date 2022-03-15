#ifndef _VSH_LIB_INCLUDE_VSHLIB_VECTOR_HPP_
#define _VSH_LIB_INCLUDE_VSHLIB_VECTOR_HPP_

#include <iostream>
#include <vector>

template<class T>
inline std::ostream &operator<<(std::ostream &os, const std::vector<T> &v)
{
    os << '[';
    if (!v.empty( ))
    {
        typename std::vector<T>::const_iterator ii = v.begin( );
        os << *ii;
        ++ii;
        for (; ii != v.end( ); ++ii)
        {
            os << ", " << *ii;
        }
    }
    os << ']';
    return os;
}

#endif /* _VSH_LIB_INCLUDE_VSHLIB_VECTOR_HPP_ */