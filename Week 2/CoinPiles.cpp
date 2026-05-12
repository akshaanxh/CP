/*
===============================================================================
                            CSES - Coin Piles
===============================================================================

QUESTION UNDERSTANDING
----------------------

We are given two coin piles:

    Left pile  = a
    Right pile = b

Allowed Operations:

1)
    Remove:
        1 coin from left pile
        2 coins from right pile

    (a,b) -> (a-1,b-2)


2)
    Remove:
        2 coins from left pile
        1 coin from right pile

    (a,b) -> (a-2,b-1)


GOAL:
    Determine whether it is possible to make BOTH piles exactly zero.


-------------------------------------------------------------------------------
EXAMPLE UNDERSTANDING
-------------------------------------------------------------------------------

Example:
    a = 2
    b = 1

We can use operation 2:

    (2,1) -> (0,0)

Possible.

Answer:
    YES


Another Example:
    a = 2
    b = 2

Possible operations:

Operation 1:
    (2,2) -> (1,0)

Now impossible.

Operation 2:
    (2,2) -> (0,1)

Again impossible.

Answer:
    NO


-------------------------------------------------------------------------------
NAIVE THOUGHT PROCESS
-------------------------------------------------------------------------------

One possible idea:
    Keep simulating operations until piles become empty.

Problem:
    a,b can be as large as 10^9.

Simulation would be far too slow.

So we need mathematical observations.


-------------------------------------------------------------------------------
CORE OBSERVATION 1
-------------------------------------------------------------------------------

Every operation removes exactly:

    3 coins total

Because:

Operation 1:
    1 + 2 = 3

Operation 2:
    2 + 1 = 3

Therefore:

    (a + b)

always decreases by 3.

So:
    Total coins MUST be divisible by 3.

Condition 1:

    (a + b) % 3 == 0


-------------------------------------------------------------------------------
WHY THIS CONDITION IS NOT ENOUGH
-------------------------------------------------------------------------------

Example:

    a = 1
    b = 5

Total:
    1 + 5 = 6

Divisible by 3.

BUT still impossible.

Why?

Because:
    One pile is too large compared to the other.

The smaller pile becomes empty too quickly.


-------------------------------------------------------------------------------
CORE OBSERVATION 2 (BALANCE CONDITION)
-------------------------------------------------------------------------------

In one move:
    Maximum removable from one pile = 2

Suppose:

    a > b

To reduce 'a' as quickly as possible,
we always remove 2 from 'a'.

Even then:
    for every 2 removed from 'a',
    at least 1 must be removed from 'b'.

Therefore:

    a <= 2*b

Similarly:

    b <= 2*a

Combined condition:

    max(a,b) <= 2 * min(a,b)


-------------------------------------------------------------------------------
FINAL CONDITIONS
-------------------------------------------------------------------------------

Both conditions must be true:

1)
    (a + b) % 3 == 0

2)
    max(a,b) <= 2 * min(a,b)

If both are true:
    YES

Otherwise:
    NO


-------------------------------------------------------------------------------
EXAMPLE DRY RUN
-------------------------------------------------------------------------------

Example:
    a = 3
    b = 3

Condition 1:
    (3+3)%3 = 0

Condition 2:
    3 <= 2*3

Both true.

Answer:
    YES


Example:
    a = 1
    b = 5

Condition 1:
    (1+5)%3 = 0

True.

Condition 2:
    5 <= 2*1

False.

Answer:
    NO


-------------------------------------------------------------------------------
PATTERN RECOGNITION
-------------------------------------------------------------------------------

This problem belongs to:

    1. Mathematics
    2. Invariant Problems
    3. Greedy Observation
    4. Constructive Logic

Common CP Pattern:
    When operations are repeated,
    look for:
        - parity
        - modulo
        - invariants
        - balance constraints


-------------------------------------------------------------------------------
IMPORTANT LEARNING
-------------------------------------------------------------------------------

In Competitive Programming:

DO NOT immediately simulate operations.

Instead ask:
    1. What changes every move?
    2. What stays invariant?
    3. Can one value become too large/small?
    4. What is the maximum effect of one move?

This thinking is extremely important in CP mathematics.


-------------------------------------------------------------------------------
TIME COMPLEXITY
-------------------------------------------------------------------------------

Each test case:
    O(1)

Total:
    O(t)


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

    // Number of test cases
    int t;
    cin >> t;

    while(t--) {

        long long a, b;
        cin >> a >> b;

        /*
            Condition 1:
            Total coins must be divisible by 3
        */

        bool divisible = ((a + b) % 3 == 0);

        /*
            Condition 2:
            Larger pile cannot exceed double
            the smaller pile
        */

        bool balanced = (max(a, b) <= 2 * min(a, b));

        // Both conditions must be true

        if(divisible && balanced) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}