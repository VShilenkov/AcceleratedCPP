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
 *    @brief      Параграф 02. Упражнение 04. Страница 057.
 *
 *    Программы вывода приветствия в рамочке, в основном, выводит строки с пробе-
 *    лами, отделяющие приветствие от горизонтальных границ рамочки, посимволь-
 *    но. Модифицируйте программу так, чтобы она записывала все пробелы в одном
 *    выражении вывода данных.
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

int main()
{
   // Запрашиваем имя человека.
   cout << "Введите, пожалуйста, свое имя: ";

   // Читаем введенное имя.
   string name;
   cin >> name;

   // Создаем сообщение, подлежащее выводу.
   const string greeting = "Привет, " + name + "!";

   // Количество пробелов, окружающих приветствие.
   unsigned int pad_left = 0;
   unsigned int pad_right = 0;
   unsigned int pad_up = 0;
   unsigned int pad_down = 0;

   cout << "Введите количество окружающих пробелов (слева, справа, сверху, снизу): " << endl;
   cin >> pad_left >> pad_right >> pad_up >> pad_down;

   // Количество выводимых строк и столбцов.
   const int rows = pad_down + pad_up + 3;
   const string::size_type cols = greeting.size() + pad_left + pad_right + 2;

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
         if (r == pad_up + 1 && c == pad_left + 1)
         {
            cout << greeting;
            c += greeting.size();
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
               if (r != 0 && r != pad_up + 1 && r != rows - 1)
               {
                  cout << string(cols - 2, ' ');
                  c += cols - 3;
               }
               else
               {
                  cout << " ";
               }
            }
            ++c;
         }
      }

      cout << endl;
   }

   return 0;
}
