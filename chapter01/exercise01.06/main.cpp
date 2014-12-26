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
 *    @brief      Параграф 01. Упражнение 06. Страница 037.
 *
 *    Что делает следующая программа, если при запросе ввести данные вы вводите
 *    два имени (например, Чарли Чаплин). Предскажите поведение программы до ее
 *    выполнения, а затем проверьте свои предсказания.
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
 
#include <iostream>
#include <string>

int main()
{
   setlocale(LC_ALL, "Russian");

   std::cout << "Как вас зовут? ";
   std::string name;
   std::cin >> name;
   std::cout << "Привет, " << name
      << std::endl << "А как вас зовут? ";
   std::cin >> name;
   std::cout << "Привет, " << name
      << "; с вами также было приятно познакомится!" << std::endl;
   return 0;
}