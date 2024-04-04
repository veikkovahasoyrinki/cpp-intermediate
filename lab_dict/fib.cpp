/**
 * @file fib.cpp
 * Contains Fibonacci-number generating functions both utilizing and not
 * utilizing memoization.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include "fib.h"

#include <map>

using std::map;

/** 
 * Calculates the nth Fibonacci number where the zeroth is defined to be 
 * 0.
 * @param n Which number to generate.
 * @return The nth Fibonacci number.
 */
unsigned long fib(unsigned long n)
{
    unsigned long a = 0, b = 1, c, i;
    if (n == 0)
        return a;
    for (i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

/** 
 * Calculates the nth Fibonacci number where the zeroth is defined to be 
 * 0. This version utilizes memoization.
 * @param n Which number to generate.
 * @return The nth Fibonacci number.
 */
unsigned long memoized_fib(unsigned long n) {
    unsigned long ret = 0;
    unsigned long b, a;
    static map< unsigned long, unsigned long > memo = {
        {0, 0},
        {1, 1},
        {2, 1}
    };
    if (memo.find(n) != memo.end()) {
        ret = memo.find(n)->second;
    } else {
        if (memo.find(n-1) != memo.end())
            a = memo.find(n-1)->second;
        if (memo.find(n-2) != memo.end())
            b = memo.find(n-2)->second;
        ret = a + b;
        memo[n] = ret;
    }
    return ret;
}
