/******************************************************************************
 *       Project: AcceleratedCPP
 * (c) Copyright: 2023
 *       Company: Home
 *                All rights reserved
 * Secrecy Level: PUBLIC
 *****************************************************************************/

/**
 *    @file       main.cpp
 *    @author     VShylienkov
 *    @brief      Параграф 07. Упражнение 07. Страница 170.
 *
 *    Измените драйверную часть программы создания таблицы перекрестных ссылок
 *    так, чтобы она выводила фразу встречается на строке, если в этой таблице
 *    указывается только одна строка, и фразу встречается на строках - в против-
 *    ном случае.
 *
 *    @see        Эффективное программирование на C++.
 *    @see        Практическое программирование на примерах.
 *    @see        Эндрю Кёниг, Барбара Му. 2002.
 */

/**
 *   Version history:
 *
 *   2023-12-08   0.1.0   VShylienkov   Initial
 */

/**
 *   В исходной функции по поиску ссылок заменяем вектор на сет.
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

bool space(char c)
{
    return std::isspace(c);
}

bool not_space(char c)
{
    return !std::isspace(c);
}

std::vector<std::string> split(const std::string &str)
{
    typedef std::string::const_iterator iter;

    std::vector<std::string> ret;

    iter i = str.begin( );
    while (i != str.end( ))
    {
        // Игнорируем ведущие пробелы.
        i = std::find_if(i, str.end( ), not_space);

        // Находим конец следующего слова.
        iter j = std::find_if(i, str.end( ), space);

        // Копируем символы из диапазона [i, j).
        if (i != str.end( ))
        {
            ret.emplace_back(i, j);
        }
        i = j;
    }
    return ret;
}

// Находим все строк, в которых есть каждое слово
// из исходного текста.
std::map<std::string, std::set<int>> xref(std::istream            &in,
                                          std::vector<std::string> find_words(const std::string &) = split)
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