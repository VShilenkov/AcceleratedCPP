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
 *    @brief      Параграф 02. Упражнение 05. Страница 057.
 *
 *    Выведите ряд символов "*" так, чтобы они образовали квадрат, прямоугольник и
 *    треугольник.
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

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
   unsigned square_edge = 10U;
   unsigned rectangle_height = 13U;
   unsigned rectangle_width = 26U;
   unsigned triangle_height = 7U;

   unsigned rows = square_edge;
   if (rows < rectangle_height) rows = rectangle_height;
   if (rows < triangle_height) rows = triangle_height;

   for (unsigned r = 0; r != rows; r++)
   {
      if (rows - r <= square_edge) cout << string(square_edge, '*') << " ";
      else cout << string(square_edge + 1, ' ');

      if (rows - r <= rectangle_height) cout << string(rectangle_width, '*') << " ";
      else cout << string(rectangle_width + 1, ' ');

      if (rows - r <= triangle_height) cout << string(triangle_height + r - rows + 1, '*');

      cout << endl;
   }

   return 0;
}