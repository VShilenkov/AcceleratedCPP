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
 *    @brief      Параграф 02. Упражнение 00. Страница 057.
 *
 *    Скомпилируйте и выполните программу, приведенную в этой главе.
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

#include <iostream>
#include <string>

// Уведомляем об использовании имен стандартной библиотеки.
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main( )
{
    // Запрашиваем имя человека.
    cout << "Введите, пожалуйста, свое имя: ";

    // Читаем введенное имя.
    string name;
    cin >> name;

    // Создаем сообщение, подлежащее выводу.
    const string greeting = "Привет, " + name + "!";

    // Количество пробелов, окружающих приветствие.
    const int pad = 1;

    // Количество выводимых строк и столбцов.
    const int               rows = pad * 2 + 3;
    const string::size_type cols = greeting.size( ) + pad * 2 + 2;

    // Выводим пустую строку, чтобы отделить вывод от ввода.
    cout << endl;

    // Выводим rows строк.
    // Инвариант: пока мы вывели r строк.
    for (int r = 0; r != rows; ++r)
    {
        string::size_type c = 0;

        // Инвариант: пока мы вывели c символов в текущую строку.
        while (c != cols)
        {
            // Пора выводить приветствие (greeting)?
            if (r == pad + 1 && c == pad + 1)
            {
                cout << greeting;
                c += greeting.size( );
            }
            else
            {
                // Мы должны выводить рамку?
                if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
                ++c;
            }
        }

        cout << endl;
    }

    return 0;
}
