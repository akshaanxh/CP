/*
===============================================================================
                        CSES - Missing Number
===============================================================================

QUESTION UNDERSTANDING
----------------------

We are given:

    Numbers from 1 to n

But:
    exactly ONE number is missing.

We need to find the missing number.


-------------------------------------------------------------------------------
EXAMPLE UNDERSTANDING
-------------------------------------------------------------------------------

Input:
    n = 5

Numbers given:
    2 3 1 5

Original sequence should be:

    1 2 3 4 5

Missing number:
    4


-------------------------------------------------------------------------------
NAIVE APPROACH
-------------------------------------------------------------------------------

One possible idea:

1. Sort the array
2. Traverse and check where sequence breaks

This works.

But:
    Sorting takes:

        O(n log n)

We can do even better.


-------------------------------------------------------------------------------
CORE OBSERVATION
-------------------------------------------------------------------------------

We know:

Numbers from 1 to n have a fixed sum.

Formula:

    Sum = n * (n + 1) / 2

If we subtract the sum of given numbers,
the remaining value will be the missing number.


-------------------------------------------------------------------------------
WHY THIS WORKS
-------------------------------------------------------------------------------

Example:
    n = 5

Expected sum:

    1 + 2 + 3 + 4 + 5 = 15

Given numbers:

    2 + 3 + 1 + 5 = 11

Difference:

    15 - 11 = 4

Missing number:
    4


-------------------------------------------------------------------------------
IMPORTANT FORMULA
-------------------------------------------------------------------------------

Sum of first n natural numbers:

                n * (n + 1)
    Sum = -----------------------
                        2


-------------------------------------------------------------------------------
APPROACH
-------------------------------------------------------------------------------

1. Calculate expected sum from 1 to n
2. Calculate actual sum of given numbers
3. Missing number = expected sum - actual sum


-------------------------------------------------------------------------------
DRY RUN
-------------------------------------------------------------------------------

Input:
    4

Numbers:
    3 2 4

Expected sum:

    4 * 5 / 2 = 10

Actual sum:

    3 + 2 + 4 = 9

Difference:

    10 - 9 = 1

Answer:
    1


-------------------------------------------------------------------------------
IMPORTANT LEARNING
-------------------------------------------------------------------------------

This is a very common CP pattern:

    "Expected Value - Actual Value"

Instead of searching manually,
we use mathematical formulas efficiently.


-------------------------------------------------------------------------------
WHY USE long long?
-------------------------------------------------------------------------------

Constraint:
    n <= 2 * 10^5

Sum can become large.

Example:

    200000 * 200001 / 2

This exceeds normal int range.

So:
    use long long


-------------------------------------------------------------------------------
PATTERN RECOGNITION
-------------------------------------------------------------------------------

This problem belongs to:

    1. Mathematics
    2. Formula Based Problems
    3. Prefix Sum Thinking
    4. Observation Problems

Common CP Pattern:
    Compare:
        expected total
        vs
        actual total


-------------------------------------------------------------------------------
ALTERNATIVE APPROACH
-------------------------------------------------------------------------------

Another famous approach:
    XOR

Because:
    x ^ x = 0

All numbers cancel except missing one.

But sum approach is simpler here.


-------------------------------------------------------------------------------
TIME COMPLEXITY
-------------------------------------------------------------------------------

Single traversal:

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

    // Input size
    long long n;
    cin >> n;

    /*
        Expected sum of numbers from 1 to n

        Formula:
            n * (n + 1) / 2
    */

    long long expectedSum = n * (n + 1) / 2;

    // Stores actual sum of given numbers
    long long actualSum = 0;

    /*
        Input contains only n-1 numbers
        because one number is missing
    */

    for(long long i = 0; i < n - 1; i++) {

        long long x;
        cin >> x;

        actualSum += x;
    }

    // Missing number
    long long missingNumber = expectedSum - actualSum;

    // Print answer
    cout << missingNumber;

    return 0;
}