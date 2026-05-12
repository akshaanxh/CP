/*
===============================================================================
                                CSES - Bit Strings
===============================================================================

QUESTION UNDERSTANDING
----------------------

We need to find:
    Number of bit strings of length n.

A bit string means:
    A string containing only:
        0 and 1

Example:
    n = 3

Possible strings:
    000
    001
    010
    011
    100
    101
    110
    111

Total = 8

So answer for n = 3 is:
    8


-------------------------------------------------------------------------------
CORE OBSERVATION
-------------------------------------------------------------------------------

For every position in the string:
    We have exactly 2 choices:
        - 0
        - 1

So:

For n = 1:
    2 choices

For n = 2:
    2 * 2 = 4 choices

For n = 3:
    2 * 2 * 2 = 8 choices

General Formula:

    Total Bit Strings = 2^n


-------------------------------------------------------------------------------
WHY MODULO IS USED
-------------------------------------------------------------------------------

The value of 2^n becomes extremely huge.

Example:
    2^1000000

This number is impossible to store in normal integer types.

So the problem asks us to print:

    (2^n) % (1e9 + 7)

Where:
    MOD = 1000000007

Modulo means:
    Remainder after division.

Example:
    10 % 3 = 1

because:
    10 = 3*3 + 1


-------------------------------------------------------------------------------
IMPORTANT MODULO PROPERTY
-------------------------------------------------------------------------------

(a * b) % m
=
((a % m) * (b % m)) % m

This allows us to:
    Take modulo at every step
    Prevent overflow


-------------------------------------------------------------------------------
APPROACH
-------------------------------------------------------------------------------

1. Start answer = 1
2. Multiply by 2 exactly n times
3. Take modulo after every multiplication

Example:
    n = 3

    ans = 1

    ans = 1 * 2 = 2
    ans = 2 * 2 = 4
    ans = 4 * 2 = 8

Final Answer = 8


-------------------------------------------------------------------------------
PATTERN RECOGNITION
-------------------------------------------------------------------------------

This problem belongs to:

    1. Combinatorics
    2. Counting Problems
    3. Modular Arithmetic
    4. Fast Exponentiation Concepts

Very Common CP Pattern:
    If each position has k choices independently:

        Total Ways = k^n


-------------------------------------------------------------------------------
TIME COMPLEXITY
-------------------------------------------------------------------------------

Loop runs n times:

    O(n)

Works perfectly for:
    n <= 10^6


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

    // Input length of bit string
    long long n;
    cin >> n;

    // Mod value given in problem
    const long long MOD = 1e9 + 7;

    // Initialize answer as 1
    long long ans = 1;

    /*
        Multiply by 2 exactly n times.

        Why?
        Because every position has:
            2 choices -> 0 or 1

        Therefore total combinations:
            2^n
    */

    for(long long i = 0; i < n; i++) {

        /*
            Taking modulo after every multiplication
            prevents overflow.
        */

        ans = (ans * 2) % MOD;
    }

    // Print final answer
    cout << ans;

    return 0;
}