/******************************************************************************
 *       Project: AcceleratedCPP
 * (c) Copyright: 2022
 *       Company: Home
 *                All rights reserved
 * Secrecy Level: PUBLIC
 *****************************************************************************/

/**
 *    @file       main.cpp
 *    @author     VShilenkov
 *    @brief      Параграф 06. Упражнение 00. Страница 151.
 *
 *    Скомпилируйте, выполните и протестируйте программы, приведенные в этой главе.
 *    (Пример a. Страница 129)
 *
 *    @see        Эффективное программирование на C++.
 *    @see        Практическое программирование на примерах.
 *    @see        Эндрю Кёниг, Барбара Му. 2002.
 */

/**
 *   Version history:
 *
 *   2022-03-15   0.1.0   VShilenkov   Initial
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> vcat(const std::vector<std::string> &top, const std::vector<std::string> &bottom)
{
    std::vector<std::string> ret = top;

    for (std::vector<std::string>::const_iterator i = bottom.begin( ); i != bottom.end( ); ++i)
    {
        ret.push_back(*i);
    }

    return ret;
}

std::vector<std::string> vcat1(const std::vector<std::string> &top, const std::vector<std::string> &bottom)
{
    std::vector<std::string> ret = top;

    ret.insert(ret.end( ), bottom.begin( ), bottom.end( ));

    return ret;
}

std::vector<std::string> vcat2(const std::vector<std::string> &top, const std::vector<std::string> &bottom)
{
    std::vector<std::string> ret = top;

    std::copy(bottom.begin(), bottom.end(), std::back_inserter(ret));

    return ret;
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v)
{
    for (typename std::vector<T>::const_iterator i = v.cbegin( ); i < v.cend( ); ++i)
    {
        os << *i << std::endl;
    }
    return os;
}

int main( )
{
    std::vector<std::string>
        up{"*********", "*********", "*       *", "*       *", "*       *", "*********", "*********"},
        down{"***", "***", "* *", "* *", "* *", "* *", "* *", "* *", "* *", "***", "***"};

    std::vector<std::string> result = vcat(up, down);

    result = vcat1(up, down);

    result = vcat2(up, down);

    std::cout << result << std::endl;
    return 0;
}