/*
===============================================================================
                            CSES - Permutations
===============================================================================

QUESTION UNDERSTANDING
----------------------

We need to construct a permutation of numbers:

    1, 2, 3, ..., n

Such that:

    No two adjacent elements have difference 1.

Meaning:

    |a[i] - a[i+1]| != 1

for every adjacent pair.


-------------------------------------------------------------------------------
WHAT IS A PERMUTATION?
-------------------------------------------------------------------------------

A permutation means:
    Arrangement of numbers using every number exactly once.

Example for n = 4:

    1 2 3 4
    2 1 4 3
    3 1 4 2

All are permutations.


-------------------------------------------------------------------------------
EXAMPLE UNDERSTANDING
-------------------------------------------------------------------------------

Example:
    n = 5

One possible answer:

    4 2 5 3 1

Check adjacent differences:

    |4-2| = 2
    |2-5| = 3
    |5-3| = 2
    |3-1| = 2

All valid.

So this is a beautiful permutation.


-------------------------------------------------------------------------------
WHY NORMAL ORDER FAILS
-------------------------------------------------------------------------------

Normal sequence:

    1 2 3 4 5

Differences:

    |1-2| = 1
    |2-3| = 1
    |3-4| = 1

Invalid.


-------------------------------------------------------------------------------
NAIVE APPROACH
-------------------------------------------------------------------------------

One possible idea:
    Generate all permutations and check validity.

Problem:
    Total permutations = n!

Impossible for large n.

Example:
    10! = 3628800

Way too large.


-------------------------------------------------------------------------------
CORE OBSERVATION
-------------------------------------------------------------------------------

Numbers having same parity differ by at least 2.

Example:

Even numbers:
    2 4 6

Differences:
    2, 2

Odd numbers:
    1 3 5

Differences:
    2, 2

So:
    placing all even numbers together
    and all odd numbers together works.


-------------------------------------------------------------------------------
MAIN CONSTRUCTION
-------------------------------------------------------------------------------

Print:

    1. All even numbers
    2. Then all odd numbers

OR vice versa.

This avoids adjacent difference of 1.


-------------------------------------------------------------------------------
EXAMPLE DRY RUN
-------------------------------------------------------------------------------

Example:
    n = 5

Even numbers:
    2 4

Odd numbers:
    1 3 5

Combined:

    2 4 1 3 5

Check:

    |2-4| = 2
    |4-1| = 3
    |1-3| = 2
    |3-5| = 2

Valid.


-------------------------------------------------------------------------------
WHY SMALL VALUES FAIL
-------------------------------------------------------------------------------

n = 1
    1

Valid.

n = 2

Possible permutations:

    1 2
    2 1

Difference always 1.

Impossible.

n = 3

Try all permutations:
    Every arrangement has adjacent difference 1.

Impossible.


Therefore:

    n = 2 and n = 3
    have NO SOLUTION.


-------------------------------------------------------------------------------
FINAL OBSERVATION
-------------------------------------------------------------------------------

If:

    n == 2 OR n == 3

Print:
    NO SOLUTION

Otherwise:
    print evens then odds.


-------------------------------------------------------------------------------
IMPORTANT LEARNING
-------------------------------------------------------------------------------

This is a classic:

    Constructive Algorithm Problem

Meaning:
    We do not calculate an answer.
    We CONSTRUCT a valid arrangement.


-------------------------------------------------------------------------------
PATTERN RECOGNITION
-------------------------------------------------------------------------------

This problem belongs to:

    1. Constructive Algorithms
    2. Mathematics
    3. Observation Problems
    4. Greedy Arrangement

Common CP Pattern:
    Build arrangement using parity/pattern observations.


-------------------------------------------------------------------------------
TIME COMPLEXITY
-------------------------------------------------------------------------------

We print numbers once:

    O(n)


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
    int n;
    cin >> n;

    /*
        No valid permutation exists
        for n = 2 or n = 3
    */

    if(n == 2 || n == 3) {

        cout << "NO SOLUTION";
        return 0;
    }

    /*
        Print all even numbers first
    */

    for(int i = 2; i <= n; i += 2) {

        cout << i << " ";
    }

    /*
        Print all odd numbers next
    */

    for(int i = 1; i <= n; i += 2) {

        cout << i << " ";
    }

    return 0;
}