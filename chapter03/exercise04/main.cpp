/******************************************************************************
 *       Project: AcceleratedCPP
 * (c) Copyright: 2014
 *       Company: Home
 *                All rights reserved
 * Secrecy Level: PUBLIC
 *****************************************************************************/

/**
 *    @file       main.cpp
 *    @author     VShilenkov
 *    @brief      Параграф 03. Упражнение 04. Страница 074.
 *
 *    Напишите программу, которая должна отслеживать оценки нескольких студентов
 *    сразу. Программа могла бы использовать синхронно два вектора: первый будет
 *    хранить имена студентов, а второй - итоговые оценки, вычисляемые после счи-
 *    тывания введенных данных. Пока используйте фиксированное количество оце-
 *    нок за выполнение домашних заданий. В разделе 4.1.3 мы узнаем, как обрабаты-
 *    вать переменное количество оценок вперемешку с именами студентов.
 *
 *    @see        Эффективное программирование на C++.
 *    @see        Практическое программирование на примерах.
 *    @see        Эндрю Кёниг, Барбара Му. 2002.
 */

/**
 *   Version history:
 *
 *   2014-12-28   0.1.0   VShilenkov   Initial
 */

#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

int main( )
{
    vector<string> students;
    vector<double> scores;
    bool           stop = false;
    while (!stop)
    {
        // Запрашиваем и читаем имя студента.
        cout << "Пожалуйста, введите свое имя: ";
        string name;
        cin >> name;
        cout << "Привет, " << name << "!" << endl;

        students.push_back(name);

        // Запрашиваем и читаем оценки по экзаменам,
        // проведенным в середине и в конце семестра.
        cout << "Пожалуйста, введите оценки по экзаменам "
                "в середине и в конце семестра: ";
        double midterm, fin;
        cin >> midterm >> fin;

        // Запрашиваем оценки за выполнение домашних заданий.
        cout << "Введите все оценки за выполнение домашних заданий, "
                "завершив ввод признаком конца файла: ";
        vector<double> homework;
        double         x;

        // Инвариант: объект homework содержит все оценки
        // за домашние задания, введенные до сих пор
        while (cin >> x)
            homework.push_back(x);

        // Проверяем, ввел ли студент оценки за домашние задания.
        typedef vector<double>::size_type vec_sz;
        vec_sz                            size = homework.size( );

        if (size == 0)
        {
            cout << endl
                 << "Необходимо ввести оценки для расчета. "
                    "Пожалуйста, попытайтесь снова. "
                 << endl;
            return 1;
        }

        // Сортируем оценки.
        sort(homework.begin( ), homework.end( ));

        // Вычисляем медианную оценку вектора homework.
        vec_sz mid = size / 2;
        double median;
        median = size % 2 == 0 ? (homework[mid] + homework[mid - 1]) / 2 : homework[mid];

        scores.push_back(0.2 * midterm + 0.4 * fin + 0.4 * median);

        cin.clear( );
        cout << "Добавить еще студента? (y/n) ";
        char c;
        cin >> c;
        if (c != 'y')
            stop = true;
    }

    for (size_t i = 0; i != students.size( ); i++)
    {
        cout << students[i] << '\t' << scores[i] << endl;
    }

    return 0;
}
