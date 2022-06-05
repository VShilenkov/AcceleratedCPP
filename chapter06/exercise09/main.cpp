/******************************************************************************
 *       Project: AcceleratedCPP
 * (c) Copyright: 2015
 *       Company: Home
 *                All rights reserved
 * Secrecy Level: PUBLIC
 *****************************************************************************/

/**
 *    @file       main.cpp
 *    @author     VShylienkov
 *    @brief      Параграф 06. Упражнение 09. Страница 151.
 *
 *    Используйте подходящий библиотечный алгоритм, чтобы конкатенировать все
 *    элементы вектора типа vector<string>.
 *
 *    @see        Эффективное программирование на C++.
 *    @see        Практическое программирование на примерах.
 *    @see        Эндрю Кёниг, Барбара Му. 2002.
 */

/**
 *   Version history:
 *
 *   2022-06-05   0.1.0   VShylienkov   Initial
 */

#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

std::string concatenate(const std::vector<std::string> &v)
{
    return std::accumulate(std::next(v.begin( )),
                           v.end( ),
                           std::string(v.front( )),
                           [](std::string result, const std::string &member) { return std::move(result) + ' ' + member; });
}

int main( )
{
    std::vector<std::string>
        vv{"Используйте", "подходящий", "библиотечный", "алгоритм,", "чтобы", "конкатенировать", "все"};
    std::cout << concatenate(vv) << std::endl;
    return 0;
}