/*
===============================================================================
                            CSES - Repetitions
===============================================================================

QUESTION UNDERSTANDING
----------------------

We are given a DNA sequence.

The string contains only characters:

    A, C, G, T

We need to find:

    The length of the longest contiguous substring
    containing only ONE repeated character.


-------------------------------------------------------------------------------
WHAT DOES "CONTIGUOUS" MEAN?
-------------------------------------------------------------------------------

Contiguous means:
    characters must be together continuously.

Example:

    "GGG"

is contiguous.

But:

    "G...G...G"

is NOT contiguous.


-------------------------------------------------------------------------------
EXAMPLE UNDERSTANDING
-------------------------------------------------------------------------------

Input:
    ATTCGGGA

Let us group repeated characters:

    A       -> length 1
    TT      -> length 2
    C       -> length 1
    GGG     -> length 3
    A       -> length 1

Longest repetition:
    GGG

Length:
    3


-------------------------------------------------------------------------------
NAIVE APPROACH
-------------------------------------------------------------------------------

One possible idea:

For every position:
    keep checking next characters.

This would work,
but can become inefficient.

Worst case:
    O(n^2)

We can solve it in a single traversal.


-------------------------------------------------------------------------------
CORE OBSERVATION
-------------------------------------------------------------------------------

We only need to track:

1. Current repetition length
2. Maximum repetition length found so far

While traversing the string:

If:
    current character == previous character

Then:
    repetition continues

Otherwise:
    repetition breaks
    reset current count


-------------------------------------------------------------------------------
APPROACH
-------------------------------------------------------------------------------

Maintain:

    currentCount
    maximumCount

Steps:

1. Start traversal from index 1
2. Compare current character with previous character
3. If same:
        increase currentCount
4. Else:
        reset currentCount to 1
5. Update maximumCount


-------------------------------------------------------------------------------
DRY RUN
-------------------------------------------------------------------------------

Input:
    ATTCGGGA

Initialize:

    currentCount = 1
    maximumCount = 1


Index 1:
    T != A

    currentCount = 1

Index 2:
    T == T

    currentCount = 2
    maximumCount = 2

Index 3:
    C != T

    currentCount = 1

Index 4:
    G != C

    currentCount = 1

Index 5:
    G == G

    currentCount = 2

Index 6:
    G == G

    currentCount = 3
    maximumCount = 3

Final Answer:
    3


-------------------------------------------------------------------------------
IMPORTANT LEARNING
-------------------------------------------------------------------------------

This problem teaches:

    Consecutive Segment Tracking

Very common in CP.

Whenever you see:
    longest streak
    longest consecutive
    repeated segment

think:
    maintain current count
    maintain maximum count


-------------------------------------------------------------------------------
PATTERN RECOGNITION
-------------------------------------------------------------------------------

This problem belongs to:

    1. Strings
    2. Linear Traversal
    3. Consecutive Counting
    4. Sliding Window Style Thinking

Common CP Pattern:
    Track continuous segments efficiently.


-------------------------------------------------------------------------------
WHY THIS IS EFFICIENT
-------------------------------------------------------------------------------

We traverse the string only once.

So complexity becomes:

    O(n)

Perfect for:
    n <= 10^6


-------------------------------------------------------------------------------
EDGE CASE
-------------------------------------------------------------------------------

Input:
    A

Answer:
    1

Our code already handles this.


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

    // Input DNA string
    string s;
    cin >> s;

    /*
        currentCount:
            stores current repetition length

        maximumCount:
            stores longest repetition found
    */

    int currentCount = 1;
    int maximumCount = 1;

    /*
        Start from index 1
        because we compare with previous character
    */

    for(int i = 1; i < s.size(); i++) {

        /*
            If current character equals previous character,
            repetition continues
        */

        if(s[i] == s[i - 1]) {

            currentCount++;
        }

        /*
            Otherwise repetition breaks,
            so reset count to 1
        */

        else {

            currentCount = 1;
        }

        // Update maximum repetition length

        maximumCount = max(maximumCount, currentCount);
    }

    // Print final answer
    cout << maximumCount;

    return 0;
}