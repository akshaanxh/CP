/*
===============================================================================
                    Codeforces - A. Domino Piling
===============================================================================

QUESTION UNDERSTANDING
----------------------

We are given:

    A board of size:
        M × N

We also have:
    unlimited domino pieces of size:

        2 × 1

Goal:
    Place the MAXIMUM number of dominoes on the board.

Rules:
    1. Each domino covers exactly 2 squares
    2. Dominoes cannot overlap
    3. Dominoes must stay inside the board
    4. Rotation is allowed


-------------------------------------------------------------------------------
WHAT DOES A DOMINO COVER?
-------------------------------------------------------------------------------

A domino always covers:

    2 cells

Example:

Horizontal:
    [ ][ ]

Vertical:
    [ ]
    [ ]


-------------------------------------------------------------------------------
CORE OBSERVATION
-------------------------------------------------------------------------------

Total cells on board:

    M * N

Each domino needs:

    2 cells

Therefore:

    Maximum dominoes =
        floor((M * N) / 2)


-------------------------------------------------------------------------------
WHY FLOOR DIVISION?
-------------------------------------------------------------------------------

Sometimes total cells are odd.

Example:
    3 × 3 board

Total cells:

    9

Each domino covers 2 cells.

Possible dominoes:

    9 / 2 = 4.5

But we cannot place half dominoes.

So:

    floor(9/2) = 4

One cell remains unused.


-------------------------------------------------------------------------------
EXAMPLE UNDERSTANDING
-------------------------------------------------------------------------------

Example 1:

Input:
    2 4

Total cells:

    2 × 4 = 8

Dominoes:

    8 / 2 = 4

Output:
    4


-------------------------------------------------------------------------------

Example 2:

Input:
    3 3

Total cells:

    3 × 3 = 9

Dominoes:

    floor(9 / 2) = 4

Output:
    4


-------------------------------------------------------------------------------
IMPORTANT OBSERVATION
-------------------------------------------------------------------------------

This problem does NOT require:
    simulation
    greedy placement
    arrangement checking

Why?

Because:
    only total area matters.

If there are enough cells,
we can always place dominoes optimally.


-------------------------------------------------------------------------------
APPROACH
-------------------------------------------------------------------------------

1. Read M and N
2. Calculate:
        (M * N) / 2
3. Print answer


-------------------------------------------------------------------------------
IMPORTANT C++ NOTE
-------------------------------------------------------------------------------

In C++:
    integer division automatically performs floor division.

Example:

    9 / 2 = 4

So:
    no special floor() function is needed.


-------------------------------------------------------------------------------
PATTERN RECOGNITION
-------------------------------------------------------------------------------

This problem belongs to:

    1. Mathematics
    2. Area Calculation
    3. Greedy Observation
    4. Formula Based Problems

Common CP Pattern:
    Compute maximum objects fitting
    using area/capacity.


-------------------------------------------------------------------------------
IMPORTANT LEARNING
-------------------------------------------------------------------------------

Many beginner CP problems look harder than they are.

Always ask:
    "Do I actually need to simulate?"

Sometimes:
    direct mathematical observation
    solves the entire problem.


-------------------------------------------------------------------------------
TIME COMPLEXITY
-------------------------------------------------------------------------------

Only one calculation:

    O(1)


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

    // Board dimensions
    int m, n;
    cin >> m >> n;

    /*
        Total cells = m * n

        Each domino covers 2 cells

        Maximum dominoes:
            floor((m*n)/2)

        Integer division in C++
        automatically performs floor division.
    */

    cout << (m * n) / 2;

    return 0;
}