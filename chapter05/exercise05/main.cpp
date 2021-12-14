/******************************************************************************
 *       Project: AcceleratedCPP
 * (c) Copyright: 2015
 *       Company: Home
 *                All rights reserved
 * Secrecy Level: PUBLIC
 *****************************************************************************/

/**
 *    @file       main.cpp
 *    @author     VShilenkov
 *    @brief      Параграф 05. Упражнение 05. Страница 127.
 *
 *    Напишите функцию center(const vector<string>&), возвращающую картин-
 *    картинку, в которой все строки исходной картинки дополняются пробелами до макси-
 *    мальной длины, а это дополнение пробелами по возможности поровну делится
 *    между левой и правой сторонами картинки. Каковы свойства картинок, для ко-
 *    которых будет полезной такая функция? Как узнать, обладает ли данная картинка
 *    такими свойствами?
 *
 *    @see        Эффективное программирование на C++.
 *    @see        Практическое программирование на примерах.
 *    @see        Эндрю Кёниг, Барбара Му. 2002.
 */

/**
 *   Version history:
 *
 *   2016-02-08   0.1.0   VShilenkov   Initial
 */

#include <algorithm>
#include <codecvt>
#include <fstream>    // IWYU pragma: keep
#include <iostream>
#include <locale>
#include <string>
#include <vector>

// IWYU pragma: no_include <memory>

template<typename T>
typename T::size_type width(const std::vector<T> &v)
{
    typename std::vector<T>::const_iterator r =
        std::max_element(v.cbegin( ), v.cend( ), [](const T &l, const T &r) -> bool { return l.size( ) < r.size( ); });

    return (r == v.cend( )) ? typename T::size_type( ) : r->size( );
}

std::vector<std::string> center(const std::vector<std::string> &v)
{
    std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> utf16conv;
    std::vector<std::u16string>                                       u16text;
    u16text.reserve(v.size( ));

    for (const std::string &s : v)
    {
        u16text.push_back(utf16conv.from_bytes(s));
    }

    const std::u16string::size_type max_width = width(u16text);

    for (std::vector<std::u16string>::iterator i = u16text.begin( ); i != u16text.end( ); ++i)
    {
        std::u16string left_tab((max_width - i->size( ) + 1U) >> 1U, u' ');
        *i = left_tab + *i;
    }

    std::vector<std::string> result;
    result.reserve(u16text.size( ));

    for (const std::u16string &s : u16text)
    {
        result.push_back(utf16conv.to_bytes(s));
    }

    return result;
}

int main( )
{
    std::ifstream            in(INPUT_FILE);
    std::string              s;
    std::vector<std::string> text, centered;

    while (std::getline(in, s))
    {
        text.push_back(s);
    }

    centered = center(text);

    for (const std::string &s : centered)
    {
        std::cout << s << std::endl;
    }

    return 0;
}