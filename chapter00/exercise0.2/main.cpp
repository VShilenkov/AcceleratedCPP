/******************************************************************************
 * Project        AcceleratedCPP
 * (c) copyright  2014
 * Company        Home
 *                All rights reserved
 * Secrecy Level  PUBLIC
 *****************************************************************************/

/**
 *    @file       main.cpp
 *    @dir        D:\Projects\C++\AcceleratedCPP\chapter00\exercise0.2
 *    @author     VShilenkov
 *    @date       2014/12/22
 *    @time       17:27:03
 *    @brief      Упражнение 0.2. Страница 27.
 *    
 *    Эффективное программирование на C++. Эндрю Кёниг, Барбара Му. 2002.
 *    
 *    Напишите программу, которая выводит следующий текст:
 *    
 *    "Это (") - кавычки, а это (\) - обратная косая черта."
 */

#include <iostream>

int main()
{
   setlocale(LC_ALL, "Russian");

   std::cout << "Это (\") - кавычки, а это (\\) - обратная косая черта.";

   return 0;
}