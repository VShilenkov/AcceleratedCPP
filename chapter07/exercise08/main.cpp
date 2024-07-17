/******************************************************************************
 *       Project: AcceleratedCPP
 * (c) Copyright: 2024
 *       Company: Home
 *                All rights reserved
 * Secrecy Level: PUBLIC
 *****************************************************************************/

/**
 *    @file       main.cpp
 *    @author     VShylienkov
 *    @brief      Параграф 07. Упражнение 08. Страница 170.
 *
 *    Измените программу создания таблицы перекрестных ссылок, чтобы она находи-
 *    ла в файле все URL-адреса и выводила все строки, на которых встречается
 *    каждый отдельный URL-адрес.
 *
 *    @see        Эффективное программирование на C++.
 *    @see        Практическое программирование на примерах.
 *    @see        Эндрю Кёниг, Барбара Му. 2002.
 */

/**
 *   Version history:
 *
 *   2024-07-17   0.1.0   VShylienkov   Initial
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
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

            if ((after[-1] == ',' || after[-1] == '.') && (isalnum(after[-2]))) --after;

            // Запоминаем URL-адрес.
            ret.emplace_back(b, after);

            // Передвигаем b для новой попытки отыскать
            // URL-адрес в этой строке.
            b = after;
        }
    }
    return ret;
}

// Находим все строки , в которых есть url адреса
std::map<std::string, std::set<int>> xref(std::istream            &in,
                                          std::vector<std::string> find_words(const std::string &) = find_urls)
{
    std::string                          line;
    int                                  line_number = 0;
    std::map<std::string, std::set<int>> ret;

    // Считываем следующую строку.
    while (getline(in, line))
    {
        ++line_number;

        // Разбиваем строку на слова.
        std::vector<std::string> words = find_words(line);

        // Помним, что каждое слово встречается на текущей строке
        for (std::vector<std::string>::const_iterator it = words.begin( ); it != words.end( ); ++it)
        {
            ret[*it].insert(line_number);
        }
    }
    return ret;
}

/**
 * Добавлен код который пытается печатать перевод на новую строку для в случае
 * если было напечатано больше символов чем разрешено. Проблема с не аскии локалями
 * в том что стандартная сишная и плюсовая строки не знают сколько символов а
 * только сколько там байт и это работает хорошо для однобайтных символов. Во
 * всех остальных случаях нужно конвертироваться в утф-8.16.32.
 */

int main( )
{
    // Вызываем функцию xref, используя функцию split по умолчанию
    std::map<std::string, std::set<int>> ret = xref(std::cin);
    unsigned                             line_length{80};

    auto countDigit = [](int i) -> unsigned { return std::floor(std::log10(i) + 1); };

    // Выводим результаты.
    for (auto it = ret.begin( ); it != ret.end( ); ++it)
    {
        // Выводим слово, ...
        const std::string pream{it->second.size() > 1 ?  " встречается на строках: " : " встречается на строке: "};
        std::cout << it->first << pream;

        unsigned left_shift_length = it->first.length( ) + pream.length( );
        if (left_shift_length > line_length)
        {
            std::cout << '\n';
            left_shift_length = 16;
            std::cout << std::string(left_shift_length, ' ');
        }
        std::string left_shift(left_shift_length, ' ');

        // ... а за ним - один или несколько номеров строк.
        std::set<int>::const_iterator line_it = it->second.begin( );

        std::cout << *line_it;    // Выводим первый номер строки.
        unsigned printed{countDigit(*line_it)};

        ++line_it;
        // Выводим остальные номера строк, если таковые имеются.
        while (line_it != it->second.end( ))
        {
            std::cout << ", ";
            printed += 2;
            auto added = countDigit(*line_it);
            if (printed + left_shift_length + added > line_length)
            {
                printed = 0;
                std::cout << '\n' << left_shift;
            }
            std::cout << *line_it;
            printed += added;
            ++line_it;
        }

        // Выводим символ новой строки, чтобы отделить каждое новое слово от следующего.
        std::cout << std::endl;
    }

    return 0;
}