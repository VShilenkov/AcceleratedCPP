/******************************************************************************
 *       Project: AcceleratedCPP
 * (c) Copyright: 2022
 *       Company: Home
 *                All rights reserved
 * Secrecy Level: PUBLIC
 *****************************************************************************/

/**
 *    @file       example_d.cpp
 *    @author     VShilenkov
 *    @brief      Параграф 06. Упражнение 00. Страница 151.
 *
 *    Скомпилируйте, выполните и протестируйте программы, приведенные в этой главе.
 *    (Пример e. Страница 134)
 *
 *    @see        Эффективное программирование на C++.
 *    @see        Практическое программирование на примерах.
 *    @see        Эндрю Кёниг, Барбара Му. 2002.
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool not_url_char(char c)
{
    // Символы, помимо буквенно-цифровых, которые
    // могут быть включены в URL-адрес.
    static const std::string url_ch = "~;/?:@=&$-_.+!*'(),";

    // Определяем, может ли символ c оказаться частью
    // URL-адресы, и возвращаем отрицание значения ответа.
    return !(std::isalnum(c) || std::find(url_ch.begin( ), url_ch.end( ), c) != url_ch.end( ));
}

std::string::const_iterator url_end(std::string::const_iterator b, std::string::const_iterator e)
{
    return std::find_if(b, e, not_url_char);
}

std::string::const_iterator url_beg(std::string::const_iterator b, std::string::const_iterator e)
{
    static const std::string            sep = "://";
    typedef std::string::const_iterator iter;

    // Итератор отмечает местонахождение разделителя.
    iter i = b;

    while ((i = std::search(i, e, sep.begin( ), sep.end( ))) != e)
    {
        // Убеждаемся, что разделитель не находится
        // в начале или конце строки.
        if (i != b && i + sep.size( ) != e)
        {
            // Итератор beg отмечает начало имени протокола.
            iter beg = i;
            while (beg != b && std::isalpha(beg[-1])) --beg;

            // Существует ли по крайней мере один подходящий
            // символ до и после разделителя
            if(beg != i && !not_url_char(i[sep.size()]))
                return beg;
        }
    }

    return e;
}

std::vector<std::string> find_urls(const std::string &s)
{
    std::vector<std::string>            ret;
    typedef std::string::const_iterator iter;
    iter                                b = s.begin( ), e = s.end( );

    // Просмотр всего содержимого входных данных
    while (b != e)
    {
        // Поиск одной или нескольких букв, стоящих
        // за буквосочетанием "://".
        b = url_beg(b, e);

        // Если поиск удался...
        if (b != e)
        {
            // ... получаем остальную часть URL-адреса.
            iter after = url_end(b, e);

            // Запоминаем URL-адрес.
            ret.emplace_back(b, after);

            // Передвигаем b для новой попытки отыскать
            // URL-адрес в этой строке.
            b = after;
        }
    }
    return ret;
}

int main( )
{
    std::string test("text with urls https://one.test http://example.com ftp://bla.dot.bla");

    auto result = find_urls(test);

    for(auto s: result)
        std::cout << s << std::endl;

    return 0;
}