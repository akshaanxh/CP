/*
===============================================================================
                Codeforces - A. In Search of an Easy Problem
===============================================================================

QUESTION UNDERSTANDING
----------------------

We are given opinions of n people about a problem.

Each person gives:
    0 -> problem is EASY
    1 -> problem is HARD

Rule:
    If AT LEAST ONE person says the problem is HARD,
    then final answer becomes:

        HARD

Otherwise:
    EASY


-------------------------------------------------------------------------------
EXAMPLE UNDERSTANDING
-------------------------------------------------------------------------------

Input:
    3
    0 0 1

Person opinions:
    easy
    easy
    hard

Since at least one person thinks it is hard:

Output:
    HARD


Another Example:

Input:
    1
    0

Only one person says easy.

Output:
    EASY


-------------------------------------------------------------------------------
CORE OBSERVATION
-------------------------------------------------------------------------------

We only need to check:

    Does there exist at least one '1' ?

If yes:
    HARD

Otherwise:
    EASY


-------------------------------------------------------------------------------
APPROACH
-------------------------------------------------------------------------------

1. Traverse all opinions
2. If any value equals 1:
        print HARD
        stop program
3. If traversal finishes:
        print EASY


-------------------------------------------------------------------------------
WHY THIS WORKS
-------------------------------------------------------------------------------

Problem statement says:

    Even one hard opinion
    is enough to change the problem.

So:
    existence of 1 determines answer.


-------------------------------------------------------------------------------
IMPORTANT CP CONCEPT
-------------------------------------------------------------------------------

This is called:

    Existence Checking

Very common beginner CP pattern.

Typical questions:
    - Is there any negative number?
    - Is there any duplicate?
    - Does any element satisfy condition?


-------------------------------------------------------------------------------
EARLY TERMINATION
-------------------------------------------------------------------------------

The moment we find:

    1

answer is already decided.

So:
    no need to check remaining values.

This is called:
    early termination

A useful CP optimization habit.


-------------------------------------------------------------------------------
DRY RUN
-------------------------------------------------------------------------------

Input:
    4
    0 0 0 1

Traversal:

    0 -> continue
    0 -> continue
    0 -> continue
    1 -> HARD immediately

Output:
    HARD


-------------------------------------------------------------------------------
PATTERN RECOGNITION
-------------------------------------------------------------------------------

This problem belongs to:

    1. Implementation
    2. Existence Checking
    3. Conditional Logic
    4. Linear Traversal

Common CP Pattern:
    Traverse array and detect whether
    some condition becomes true.


-------------------------------------------------------------------------------
TIME COMPLEXITY
-------------------------------------------------------------------------------

Worst Case:
    O(n)

Best Case:
    O(1)
    if first element is 1


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

    // Number of people
    int n;
    cin >> n;

    // Traverse all opinions
    for(int i = 0; i < n; i++) {

        int opinion;
        cin >> opinion;

        /*
            If even one person says HARD,
            answer becomes HARD immediately
        */

        if(opinion == 1) {

            cout << "HARD";
            return 0;
        }
    }

    /*
        If no 1 was found,
        problem is EASY
    */

    cout << "EASY";

    return 0;
}