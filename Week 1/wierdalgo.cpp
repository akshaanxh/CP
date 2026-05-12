/*
===============================================================================
                        CSES - Weird Algorithm
===============================================================================

QUESTION UNDERSTANDING
----------------------

We are given a positive integer n.

We repeatedly perform operations:

1)
    If n is EVEN:
        n = n / 2

2)
    If n is ODD:
        n = 3*n + 1

We continue this process until:

    n == 1

We must print every value of n during the process.


-------------------------------------------------------------------------------
EXAMPLE UNDERSTANDING
-------------------------------------------------------------------------------

Example:
    n = 3

Step-by-step:

    3 is odd
    3*3 + 1 = 10

    10 is even
    10/2 = 5

    5 is odd
    3*5 + 1 = 16

    16 is even
    16/2 = 8

    8 is even
    8/2 = 4

    4 is even
    4/2 = 2

    2 is even
    2/2 = 1

Sequence:

    3 10 5 16 8 4 2 1


-------------------------------------------------------------------------------
CORE OBSERVATION
-------------------------------------------------------------------------------

This problem is purely simulation.

We simply:
    - check whether current number is odd/even
    - apply the required operation
    - print values until n becomes 1

No advanced mathematics required.


-------------------------------------------------------------------------------
ODD / EVEN CHECK
-------------------------------------------------------------------------------

In programming:

    n % 2 == 0
means:
    n is even

Otherwise:
    n is odd


-------------------------------------------------------------------------------
IMPORTANT NOTE ABOUT DATA TYPES
-------------------------------------------------------------------------------

Even though:
    n <= 10^6

During operations:
    3*n + 1

the number can temporarily become much larger.

Therefore:
    use long long

instead of int.


-------------------------------------------------------------------------------
APPROACH
-------------------------------------------------------------------------------

1. Print current value of n
2. While n is not 1:
        - if n is even:
              divide by 2
        - else:
              multiply by 3 and add 1
3. Print every updated value


-------------------------------------------------------------------------------
DRY RUN
-------------------------------------------------------------------------------

Input:
    6

Step 1:
    6 is even
    6/2 = 3

Step 2:
    3 is odd
    3*3 + 1 = 10

Step 3:
    10 is even
    10/2 = 5

Continue...

Sequence:
    6 3 10 5 16 8 4 2 1


-------------------------------------------------------------------------------
PATTERN RECOGNITION
-------------------------------------------------------------------------------

This problem belongs to:

    1. Simulation
    2. Implementation
    3. Basic Number Theory

Common CP Pattern:
    Repeatedly apply rules until
    a stopping condition is reached.


-------------------------------------------------------------------------------
ABOUT THIS ALGORITHM
-------------------------------------------------------------------------------

This is famous as:

    The Collatz Conjecture

It is an unsolved mathematical problem.

The conjecture says:
    Starting from any positive integer,
    the sequence eventually reaches 1.

For this problem:
    we simply simulate it.


-------------------------------------------------------------------------------
TIME COMPLEXITY
-------------------------------------------------------------------------------

Depends on sequence length.

For given constraints:
    easily acceptable.


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

    // Using long long because values can grow large
    long long n;
    cin >> n;

    // Print values until n becomes 1
    while(n != 1) {

        // Print current value
        cout << n << " ";

        /*
            If n is even:
                divide by 2
        */

        if(n % 2 == 0) {
            n /= 2;
        }

        /*
            If n is odd:
                multiply by 3 and add 1
        */

        else {
            n = 3 * n + 1;
        }
    }

    // Print final 1
    cout << 1;

    return 0;
}