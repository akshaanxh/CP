/*
===============================================================================
                            Codeforces - A. Team
===============================================================================

QUESTION UNDERSTANDING
----------------------

Three friends:
    Petya
    Vasya
    Tonya

are participating in a programming contest.

For every problem:
    each friend either:
        knows the solution -> 1
        does not know      -> 0

Rule:
    The team will solve a problem ONLY IF
    at least TWO friends are sure about the solution.

Task:
    Count how many problems the team will solve.


-------------------------------------------------------------------------------
EXAMPLE UNDERSTANDING
-------------------------------------------------------------------------------

Input:
    3
    1 1 0
    1 1 1
    1 0 0

Problem 1:
    1 1 0

Two friends know the solution.
So:
    they solve it.

Problem 2:
    1 1 1

All three know the solution.
So:
    they solve it.

Problem 3:
    1 0 0

Only one friend knows the solution.
Not enough.

Total solved:
    2


-------------------------------------------------------------------------------
CORE OBSERVATION
-------------------------------------------------------------------------------

Each line contains only:
    0 or 1

So:
    sum of values
    =
    number of friends who know the solution.

Example:

    1 1 0

Sum:
    1 + 1 + 0 = 2

Meaning:
    two friends are sure.


-------------------------------------------------------------------------------
APPROACH
-------------------------------------------------------------------------------

For every problem:

1. Read three integers:
        a, b, c

2. Calculate:
        a + b + c

3. If sum >= 2:
        increase answer count

4. Print total answer


-------------------------------------------------------------------------------
WHY THIS WORKS
-------------------------------------------------------------------------------

Because:
    each 1 represents one confident friend.

So:
    total sum directly tells us
    how many friends know the solution.


-------------------------------------------------------------------------------
DRY RUN
-------------------------------------------------------------------------------

Input:
    2
    1 0 0
    0 1 1


Problem 1:
    1 + 0 + 0 = 1

Only one friend knows.
Do not count.


Problem 2:
    0 + 1 + 1 = 2

Two friends know.
Count it.

Final Answer:
    1


-------------------------------------------------------------------------------
IMPORTANT LEARNING
-------------------------------------------------------------------------------

This is a basic implementation problem.

It teaches:
    condition counting

Very common CP pattern:
    count rows satisfying some condition.


-------------------------------------------------------------------------------
PATTERN RECOGNITION
-------------------------------------------------------------------------------

This problem belongs to:

    1. Implementation
    2. Counting
    3. Conditional Logic

Common CP Pattern:
    Traverse input
    check condition
    maintain answer counter


-------------------------------------------------------------------------------
TIME COMPLEXITY
-------------------------------------------------------------------------------

We process each problem once:

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

    // Number of problems
    int n;
    cin >> n;

    // Stores number of problems the team will solve
    int solvedProblems = 0;

    // Process every problem
    for(int i = 0; i < n; i++) {

        int a, b, c;

        cin >> a >> b >> c;

        /*
            Sum represents how many friends
            know the solution
        */

        if(a + b + c >= 2) {

            solvedProblems++;
        }
    }

    // Print final answer
    cout << solvedProblems;

    return 0;
}