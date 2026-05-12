/*
===============================================================================
                        CSES - Increasing Array
===============================================================================

QUESTION UNDERSTANDING
----------------------

We are given an array of integers.

We need to make the array:

    NON-DECREASING

Meaning:

    a[i] >= a[i-1]

for every index.

Allowed Operation:
    Increase any element by 1 in one move.

Goal:
    Find the MINIMUM number of moves required.


-------------------------------------------------------------------------------
IMPORTANT NOTE
-------------------------------------------------------------------------------

The problem says:

    "increasing"

But condition actually means:

    every element should be at least as large
    as the previous one.

So valid arrays are:

    1 2 2 5 8

because:
    equal elements are allowed.


-------------------------------------------------------------------------------
EXAMPLE UNDERSTANDING
-------------------------------------------------------------------------------

Input:
    3 2 5 1 7

We traverse from left to right.


Step 1:
    Compare 2 with 3

    2 < 3

To make it valid:
    increase 2 -> 3

Moves needed:
    1

Array becomes:
    3 3 5 1 7


Step 2:
    Compare 5 with 3

    5 >= 3

Already valid.


Step 3:
    Compare 1 with 5

    1 < 5

Increase 1 -> 5

Moves needed:
    4

Array becomes:
    3 3 5 5 7


Step 4:
    Compare 7 with 5

Already valid.


Total moves:

    1 + 4 = 5


-------------------------------------------------------------------------------
NAIVE THOUGHT PROCESS
-------------------------------------------------------------------------------

One possible idea:
    Keep increasing smaller elements one-by-one.

Example:

    1 -> 2 -> 3 -> 4 -> 5

Problem:
    Differences can be huge.

Example:
    1 and 10^9

Performing increments literally would be too slow.

Instead:
    directly calculate how many increments are needed.


-------------------------------------------------------------------------------
CORE OBSERVATION
-------------------------------------------------------------------------------

If:

    a[i] < a[i-1]

then minimum increments required are:

    a[i-1] - a[i]

Because:
    current element must become equal to previous.


-------------------------------------------------------------------------------
IMPORTANT GREEDY INSIGHT
-------------------------------------------------------------------------------

To minimize operations:

    Make current element exactly equal
    to previous element.

NOT larger.

This gives minimum possible moves.


-------------------------------------------------------------------------------
APPROACH
-------------------------------------------------------------------------------

Traverse array from left to right.

For every element:

1.
    If current element is smaller than previous:

        add difference to answer

2.
    Update current element to previous value

This ensures:
    future comparisons remain correct.


-------------------------------------------------------------------------------
DRY RUN
-------------------------------------------------------------------------------

Input:
    3 2 5 1 7


Index 1:
    2 < 3

Moves:
    3 - 2 = 1

Array:
    3 3 5 1 7


Index 2:
    5 >= 3

No change.


Index 3:
    1 < 5

Moves:
    5 - 1 = 4

Array:
    3 3 5 5 7


Index 4:
    7 >= 5

No change.


Total:
    1 + 4 = 5


-------------------------------------------------------------------------------
IMPORTANT LEARNING
-------------------------------------------------------------------------------

This problem teaches a very important CP concept:

DO NOT simulate operations one-by-one.

Instead:
    mathematically calculate total effect.

This is a huge optimization technique in CP.


-------------------------------------------------------------------------------
PATTERN RECOGNITION
-------------------------------------------------------------------------------

This problem belongs to:

    1. Greedy
    2. Array Traversal
    3. Prefix Constraint Problems
    4. Simulation Optimization

Common CP Pattern:
    Maintain validity while traversing left-to-right.


-------------------------------------------------------------------------------
WHY WE UPDATE THE ARRAY
-------------------------------------------------------------------------------

Example:
    3 2 1

After fixing 2:

    3 3 1

Now:
    1 must be compared with updated value 3,
    not original value 2.

So updating array is necessary.


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
    int n;
    cin >> n;

    // Store array
    vector<long long> arr(n);

    for(int i = 0; i < n; i++) {

        cin >> arr[i];
    }

    /*
        Stores total number of moves

        Use long long because answer can become large
    */

    long long moves = 0;

    /*
        Traverse from second element
        and compare with previous element
    */

    for(int i = 1; i < n; i++) {

        /*
            If current element is smaller,
            increase it to previous value
        */

        if(arr[i] < arr[i - 1]) {

            // Add required increments
            moves += (arr[i - 1] - arr[i]);

            // Update current element
            arr[i] = arr[i - 1];
        }
    }

    // Print total moves
    cout << moves;

    return 0;
}