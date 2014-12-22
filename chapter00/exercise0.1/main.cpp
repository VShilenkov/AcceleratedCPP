/******************************************************************************
 * Project        AcceleratedCPP
 * (c) copyright  2014
 * Company        Home
 *                All rights reserved
 * Secrecy Level  PUBLIC
 *****************************************************************************/

/**
 *    @file       main.cpp
 *    @dir        D:\Projects\C++\AcceleratedCPP\chapter00\exercise0.1
 *    @author     VShilenkov
 *    @date       2014/12/22
 *    @time       17:17:13
 *    @brief      Упражнение 0.1. Страница 27.
 *
 *    Эффективное программирование на C++. Эндрю Кёниг, Барбара Му. 2002.
 *
 *    Скомпилируйте и выполните программу, которая выводит текст "Привет, мир!".
 *
 */

#include <iostream>

int main()
{
   setlocale(LC_ALL, "Russian");

   std::cout << "Привет, мир!";

   return 0;
}