/*
===============================================================================
                            CSES - Trailing Zeros
===============================================================================

QUESTION UNDERSTANDING
----------------------

We need to find:
    Number of trailing zeros in n!

Factorial means:

    n! = 1 * 2 * 3 * 4 * ... * n

Example:

    5! = 120

Trailing zeros:
    1

Another Example:

    20! = 2432902008176640000

Trailing zeros:
    4


-------------------------------------------------------------------------------
NAIVE APPROACH (WHY IT FAILS)
-------------------------------------------------------------------------------

One possible thought:

1. Calculate n!
2. Keep dividing by 10
3. Count how many zeros appear at the end

Problem:
    Factorials become extremely huge.

Example:
    20! is already very large.

For:
    n = 10^9

It is completely impossible to calculate factorial directly.

So we need mathematical observation.


-------------------------------------------------------------------------------
CORE OBSERVATION
-------------------------------------------------------------------------------

A trailing zero is created by:

    10 = 2 * 5

So:
    Every pair of (2,5) creates one trailing zero.

In factorials:
    Factors of 2 are very common.
    Factors of 5 are fewer.

Therefore:

    Number of trailing zeros
    =
    Number of times 5 appears in prime factorization.


-------------------------------------------------------------------------------
HOW TO COUNT FACTORS OF 5
-------------------------------------------------------------------------------

We count:

1. Numbers divisible by 5
2. Numbers divisible by 25
3. Numbers divisible by 125
4. and so on...

Why?

Because:
    25 = 5 * 5
    contributes TWO factors of 5.

Similarly:
    125 = 5 * 5 * 5
    contributes THREE factors of 5.


-------------------------------------------------------------------------------
FORMULA
-------------------------------------------------------------------------------

Trailing Zeros =

    floor(n/5)
  + floor(n/25)
  + floor(n/125)
  + ...


-------------------------------------------------------------------------------
EXAMPLE DRY RUN
-------------------------------------------------------------------------------

Example:
    n = 20

Count multiples of 5:

    20 / 5 = 4

Count multiples of 25:

    20 / 25 = 0

Total trailing zeros:

    4


Another Example:
    n = 100

    100 / 5   = 20
    100 / 25  = 4
    100 / 125 = 0

Total:

    20 + 4 = 24

So:
    100! has 24 trailing zeros.


-------------------------------------------------------------------------------
PATTERN RECOGNITION
-------------------------------------------------------------------------------

This problem belongs to:

    1. Mathematics
    2. Prime Factor Counting
    3. Number Theory
    4. Observation Based Problems

Very Common CP Pattern:
    Instead of computing huge values directly,
    count important prime factors mathematically.


-------------------------------------------------------------------------------
IMPORTANT LEARNING
-------------------------------------------------------------------------------

In Competitive Programming:

DO NOT always simulate literally.

Instead:
    - Observe mathematical properties
    - Reduce the problem
    - Count efficiently

This is one of the most important CP skills.


-------------------------------------------------------------------------------
TIME COMPLEXITY
-------------------------------------------------------------------------------

We repeatedly divide by powers of 5.

Complexity:

    O(log5(n))

Very efficient.


-------------------------------------------------------------------------------
SPACE COMPLEXITY
-------------------------------------------------------------------------------

O(1)


===============================================================================
                                    CODE
===============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    // Input value
    long long n;
    cin >> n;

    // Stores total trailing zeros
    long long zeros = 0;

    /*
        Start with power = 5

        We count:
            n/5
            n/25
            n/125
            ...

        until power becomes greater than n.
    */

    for(long long power = 5; power <= n; power *= 5) {

        zeros += n / power;
    }

    // Print final answer
    cout << zeros;

    return 0;
}