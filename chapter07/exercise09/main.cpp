/******************************************************************************
 *       Project: AcceleratedCPP
 * (c) Copyright: 2024
 *       Company: Home
 *                All rights reserved
 * Secrecy Level: PUBLIC
 *****************************************************************************/

/**
 *    @file       main.cpp
 *    @author     VShylienkov
 *    @brief      Параграф 07. Упражнение 09. Страница 170.
 *
 *    (Задание повышенной сложности.) Реализация функции nrand, приведенная в
 *    разделе 7.4.4, не будет работать для аргументов, превышающих значение
 *    RAND_MAX. Обычно это ограничение — не проблема, поскольку RAND_MAX часто
 *    является максимально возможным целым числом. Тем не менее существуют
 *    С++-среды, в которых RAND_MAX гораздо меньше максимально возможного целого
 *    числа. Например, довольно редко значение RAND_MAX оказывается равным числу
 *    32767 (2^15 — 1), в то время как максимально возможное целое число равно
 *    2147483647 (2^31 - 1). Переделайте функцию nrand так, чтобы она нормально
 *    работала для всех значений п.
 *
 *    @sa   https://mathalope.co.uk/2014/10/26/accelerated-c-solution-to-exercise-7-9/
 * 
 *    @see        Эффективное программирование на C++.
 *    @see        Практическое программирование на примерах.
 *    @see        Эндрю Кёниг, Барбара Му. 2002.
 */

/**
 *   Version history:
 *
 *   2024-07-19   0.1.0   VShylienkov   Initial
 */

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <map>
#include <random>
#include <stdexcept>

/**
 * @brief sets current number that myrand can generate up to
 *
 *  If requested negative or higher then RAND_MAX - does nothing
 *
 * @param n     limit for generation
 * @return int  current limit
 */
int rand_max(int n = 0)
{
    static int s_random_driver_limit{RAND_MAX};
    if (n > 0 && n <= RAND_MAX)
    {
        s_random_driver_limit = (n == 1) ? RAND_MAX : n;
    }
    return s_random_driver_limit;
}

/**
 * @brief generate random number with controllable upper limit
 *
 * @return int  random number [0, rand_max]
 */
int myrand( )
{
    const auto &drv_max{rand_max( )};
    const int   bucket_size = RAND_MAX / drv_max;
    int         result{0};

    do
    {
        result = rand( ) / bucket_size;    // NOLINT(cert-msc30-c,cert-msc50-cpp,concurrency-mt-unsafe)
    } while (result > drv_max);
    return result;
}

/**
 * @brief generate random number in [0, n) using myrand() driver
 *
 * @param n     upper limit
 * @return int  evenly distributed random number in requested range
 */
int nrand(int n)
{
    const auto &rmax{rand_max( )};
    int         result{0};

    if (n <= rmax)
    {
        const int bucket_size = rmax / n;
        do
        {
            result = myrand( ) / bucket_size;
        } while (result >= n);
    }
    else
    {
        const float fn          = n;
        const int   bucket_size = std::ceil(fn / rmax);

        do
        {
            const int bucket   = myrand( );
            const int reminder = nrand(bucket_size);
            result             = bucket * bucket_size + reminder;
        } while (result >= n);
    }
    return result;
}

/**
 * @brief print number with given index in five columns
 *
 * @param number    what to print
 * @param index     index of that number
 */
void print_ith(int number, int index)
{
    const int numbersPerLine = 5;
    // first in the raw
    if ((index % numbersPerLine) == 0)
    {
        std::cout << number;
    }
    else
    {
        std::cout << ", " << number;

        // start a new line
        if ((index != 0) && ((index + 1) % numbersPerLine == 0))
        {
            std::cout << std::endl;
        }
    }
}

/**
 * @brief generate set of random numbers of given size within [0,n)
 *
 *  Evenly distributed random numbers with driver myrand. Frequency graph
 *  is displayed
 *
 * @param n                     upper limit
 * @param numbersToGenerate     size of set
 */
void generate_set(int n, int numbersToGenerate = 100)
{
    // Generate random numbers within the range [0, n)

    // Display the limits
    std::cout << "randomOutcomeLimit: " << n << std::endl;
    std::cout << "randomDriverLimit: " << rand_max( ) << "\n";

    std::map<int, unsigned> hlist;

    // Display the randomOutcomes
    for (int i = 0; i < numbersToGenerate; ++i)
    {
        auto rvalue = nrand(n);
        ++hlist[rvalue];
        // print_ith(rvalue, i);
    }

    if (numbersToGenerate > 999)
    {
        for (auto [k, v] : hlist)
        {
            while (v > 100)
            {
                v /= 10;
            }
            std::cout << k << '\t' << std::string(v, '|') << '\n';
        }
    }
}

int main( )
{
    std::random_device r_device;
    srand(r_device( ));

    rand_max(2);
    generate_set(17, 100000);

    rand_max(5);
    generate_set(17, 100000);

    rand_max(16);
    generate_set(17, 100000);

    rand_max(1);
    generate_set(17, 100000);

    return 0;
}
