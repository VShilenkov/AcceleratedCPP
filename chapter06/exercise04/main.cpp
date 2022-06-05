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
 *    @brief      Параграф 06. Упражнение 03. Страница 151.
 *
 *    Внесите изменения в программу, написанную вами в качестве ответа на предыдущее
 *    упражнение, чтобы в ней выполнялось копирование из вектора u в вектор v. Сущест-
 *    вует по крайней мере два возможных способа изменить эту программу. Реализуйте
 *    оба и опишите сравнительные преимущества и недостатки каждого способа.
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
#include <string>
#include <vector>
#include <iterator>

int main( )
{
    std::vector<int> u(10,100);
    std::vector<int> v(u.size());
    std::copy(u.begin(), u.end(), v.begin());
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout<<std::endl;

    std::vector<int> w;
    std::copy(u.begin(), u.end(), std::back_inserter(w));
    std::copy(w.begin(), w.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout<<std::endl;
    return 0;
}