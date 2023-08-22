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
 *    @brief      Параграф 07. Упражнение 05. Страница 170.
 *
 *    Переделайте программу построения предложения на основе заданных грамматических
 *    правил, используя в качестве структуры данных для создания предложения тип
 *    list.
 *
 *    @see        Эффективное программирование на C++.
 *    @see        Практическое программирование на примерах.
 *    @see        Эндрю Кёниг, Барбара Му. 2002.
 */

/**
 *   Version history:
 *
 *   2023-08-22   0.1.0   VShylienkov   initial
 */

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <random>
#include <stdexcept>
#include <string>
#include <vector>
#include <list>

using Rule            = std::vector<std::string>;
using Rule_collection = std::vector<Rule>;
using Grammar         = std::map<std::string, Rule_collection>;

std::vector<std::string> split(const std::string &s)
{
    std::vector<std::string>       ret;
    typedef std::string::size_type string_size;
    string_size                    i = 0;

    while (i != s.size( ))
    {
        while (i != s.size( ) && isspace(s[i]))
        {
            ++i;
        }

        string_size j = i;

        while (j != s.size( ) && !isspace(s[j]))
        {
            ++j;
        }

        if (i != j)
        {
            ret.push_back(s.substr(i, j - i));
            i = j;
        }
    }

    return ret;
}

// считываем грамматику из данного входного потока.
Grammar read_grammar(std::istream &in)
{
    Grammar     ret;
    std::string line;

    // Считываем входные данные.
    while (std::getline(in, line))
    {
        // С помощью функции split() разбиваем входные данные на отдельные слова.
        std::vector<std::string> entry = split(line);

        if (!entry.empty( ))
        {
            // Используем категорию, чтобы сохранить соответствующее правило.
            ret[entry[0]].push_back(Rule(entry.begin( ) + 1, entry.end( )));
        }
    }
    return ret;
}

bool bracketed(const std::string &s)
{
    return s.size( ) > 2 && s.front( ) == '<' && s.back( ) == '>';
}

int nrand(int n)
{
    if (n <= 0 || n > RAND_MAX)
        throw std::domain_error("Аргумент функции nrand вне допустимого диапазона");

    const int bucket_size = RAND_MAX / n;
    int       r;

    do
    {
        r = rand( ) / bucket_size;
    } while (r >= n);
    return r;
}

void gen_aux(const Grammar &g, const std::string &word, std::list<std::string> &ret)
{
    if (!bracketed(word))
    {
        ret.push_back(word);
    }
    else
    {
        Grammar::const_iterator it = g.find(word);
        if (it == g.end( ))
        {
            throw std::logic_error("Пустое правило");
        }

        const Rule_collection &c = it->second;
        const Rule            &r = c[nrand(c.size( ))];

        for (Rule::const_iterator i = r.begin( ); i != r.end( ); ++i)
        {
            gen_aux(g, *i, ret);
        }
    }
}

std::list<std::string> gen_sentence(const Grammar &g)
{
    std::list<std::string> ret;
    gen_aux(g, "<предложение>", ret);
    return ret;
}

int main( )
{
    std::srand(std::time(nullptr));
    // Генерируем предложение.

    std::string              filename{"grammar.txt"};
    std::fstream             s{filename, s.in};
    std::list<std::string> sentence = gen_sentence(read_grammar(s));

    std::list<std::string>::const_iterator it = sentence.begin( );
    if (!sentence.empty( ))
    {
        std::cout << *it;
        ++it;
    }

    while (it != sentence.end( ))
    {
        std::cout << ' ' << *it;
        ++it;
    }

    std::cout << std::endl;
    return 0;
}