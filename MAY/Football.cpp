/*
===============================================================================
                        Codeforces - A. Football
===============================================================================

QUESTION UNDERSTANDING
----------------------

We are given a string consisting only of:

    '0' and '1'

Meaning:
    0 -> players of one team
    1 -> players of another team

A situation becomes DANGEROUS if:

    there are at least 7 consecutive
    identical characters.

Meaning:
    0000000
or
    1111111

Task:
    Determine whether the situation is dangerous.


-------------------------------------------------------------------------------
EXAMPLE UNDERSTANDING
-------------------------------------------------------------------------------

Input:
    001001

There are no 7 consecutive equal characters.

Output:
    NO


-------------------------------------------------------------------------------

Input:
    1000000001

Consecutive zeros:

    00000000

Length:
    8

Since:
    8 >= 7

Situation is dangerous.

Output:
    YES


-------------------------------------------------------------------------------
CORE OBSERVATION
-------------------------------------------------------------------------------

We only need to track:

    current consecutive streak length

If current character equals previous character:
    streak continues

Otherwise:
    streak resets to 1


-------------------------------------------------------------------------------
IMPORTANT INSIGHT
-------------------------------------------------------------------------------

We do NOT need separate counting for:
    zeros and ones

Because:
    we only care about consecutive repetition.


-------------------------------------------------------------------------------
APPROACH
-------------------------------------------------------------------------------

1. Traverse the string
2. Compare current character with previous character
3. If same:
        increase streak count
4. Else:
        reset streak to 1
5. If streak becomes >= 7:
        print YES immediately
6. If traversal finishes:
        print NO


-------------------------------------------------------------------------------
WHY EARLY TERMINATION?
-------------------------------------------------------------------------------

The moment we find:

    7 consecutive equal characters

answer is already decided.

So:
    no need to continue traversal.

This is called:
    early termination

A useful CP optimization habit.


-------------------------------------------------------------------------------
DRY RUN
-------------------------------------------------------------------------------

Input:
    11110111011101

Traversal:

    1 -> count = 1
    1 -> count = 2
    1 -> count = 3
    1 -> count = 4
    0 -> reset to 1
    1 -> reset to 1
    1 -> count = 2
    1 -> count = 3

No streak reaches 7.

Output:
    NO


-------------------------------------------------------------------------------
IMPORTANT LEARNING
-------------------------------------------------------------------------------

This problem teaches:

    Consecutive Streak Tracking

Very common CP pattern.

Typical problems:
    - longest repetition
    - consecutive ones
    - repeated characters
    - dangerous sequence detection


-------------------------------------------------------------------------------
PATTERN RECOGNITION
-------------------------------------------------------------------------------

This problem belongs to:

    1. Strings
    2. Consecutive Counting
    3. Linear Traversal
    4. Streak Tracking

Common CP Pattern:
    Track length of continuous segments.


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

    // Input football situation string
    string s;
    cin >> s;

    /*
        currentCount:
            stores current consecutive streak
    */

    int currentCount = 1;

    /*
        Traverse from second character
    */

    for(int i = 1; i < s.size(); i++) {

        /*
            If current character equals previous,
            streak continues
        */

        if(s[i] == s[i - 1]) {

            currentCount++;
        }

        /*
            Otherwise streak breaks,
            so reset count
        */

        else {

            currentCount = 1;
        }

        /*
            Dangerous situation found
        */

        if(currentCount >= 7) {

            cout << "YES";
            return 0;
        }
    }

    // No dangerous streak found
    cout << "NO";

    return 0;
}