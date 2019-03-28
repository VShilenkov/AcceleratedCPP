/******************************************************************************
 *       Project: AcceleratedCPP
 * (c) Copyright: 2014
 *       Company: Home
 *                All rights reserved
 * Secrecy Level: PUBLIC
 *****************************************************************************/

/**
 *    @file       main_ex1.cpp
 *    @author     VShilenkov
 *    @brief      Параграф 01. Упражнение 00. Страница 036.
 *
 *    Скомпилируйте, выполните и протестируйте программы, представленны в этой
 *    главе. (Пример 01. Страница 032)
 *
 *    @see        Эффективное программирование на C++.
 *    @see        Практическое программирование на примерах.
 *    @see        Эндрю Кёниг, Барбара Му. 2002.
 */

/**
 *   Version history:
 *
 *   2014-12-24   0.1.0   VShilenkov   Initial
 */

// Запрашиваем имя пользователя и
// генерируем приветствие в рамочке.
#include <iostream>
#include <string>

int main( )
{
    std::cout << "Введите, пожалуйста, свое имя: ";
    std::string name;
    std::cin >> name;

    // Создаем сообщение, подлежащее выводу.
    const std::string greeting = "Привет, " + name + "!";

    // Создаем вторую и четвертую строки приветствия.
    const std::string spaces(greeting.size( ), ' ');
    const std::string second = "* " + spaces + " *";

    // Создаем первую и пятую строки приветствия.
    const std::string first(second.size( ), '*');

    // Выводим все строки.
    std::cout << std::endl;
    std::cout << first << std::endl;
    std::cout << second << std::endl;
    std::cout << "* " << greeting << " *" << std::endl;
    std::cout << second << std::endl;
    std::cout << first << std::endl;

    return 0;
}
