/*
===============================================================================
                    Codeforces - A. Helpful Maths
===============================================================================

QUESTION UNDERSTANDING
----------------------

We are given a string representing a sum.

Example:

    3+2+1

The string contains only:
    1, 2, 3 and '+'

Task:
    Rearrange the numbers so that they appear in:

        NON-DECREASING ORDER

Meaning:
    smallest to largest.

Example:

    3+2+1

becomes:

    1+2+3


-------------------------------------------------------------------------------
IMPORTANT OBSERVATION
-------------------------------------------------------------------------------

The numbers are ONLY:

    1
    2
    3

So instead of sorting generally,
we can simply:

    count how many 1s
    count how many 2s
    count how many 3s

Then print them in order.


-------------------------------------------------------------------------------
EXAMPLE UNDERSTANDING
-------------------------------------------------------------------------------

Input:
    1+3+2+1

Count:

    1 -> 2 times
    2 -> 1 time
    3 -> 1 time

Now print in sorted order:

    1+1+2+3


-------------------------------------------------------------------------------
NAIVE APPROACH
-------------------------------------------------------------------------------

One possible idea:

1. Extract all numbers
2. Store in array/vector
3. Sort vector
4. Print with '+'

This works.

But:
    since numbers are only 1,2,3

frequency counting is simpler.


-------------------------------------------------------------------------------
CORE OBSERVATION
-------------------------------------------------------------------------------

Because range of values is tiny,
we can use:

    Counting / Frequency approach

instead of sorting.


-------------------------------------------------------------------------------
APPROACH
-------------------------------------------------------------------------------

1. Traverse the string
2. Count:
        number of 1s
        number of 2s
        number of 3s

3. Print:
        all 1s first
        then 2s
        then 3s

4. Add '+' appropriately


-------------------------------------------------------------------------------
WHY WE IGNORE '+'
-------------------------------------------------------------------------------

We only care about numbers.

So during traversal:

    if character is '+'
        skip it

Only digits matter.


-------------------------------------------------------------------------------
DRY RUN
-------------------------------------------------------------------------------

Input:
    3+1+2+1

Traversal:

    3 -> count3++
    + -> ignore
    1 -> count1++
    + -> ignore
    2 -> count2++
    + -> ignore
    1 -> count1++

Final counts:

    count1 = 2
    count2 = 1
    count3 = 1

Output:

    1+1+2+3


-------------------------------------------------------------------------------
IMPORTANT LEARNING
-------------------------------------------------------------------------------

This problem teaches:

    Frequency Counting

Very common CP optimization.

Whenever:
    value range is very small

consider:
    counting instead of sorting.


-------------------------------------------------------------------------------
PATTERN RECOGNITION
-------------------------------------------------------------------------------

This problem belongs to:

    1. Strings
    2. Sorting
    3. Frequency Counting
    4. Implementation

Common CP Pattern:
    Use counting when value range is tiny.


-------------------------------------------------------------------------------
TIME COMPLEXITY
-------------------------------------------------------------------------------

Single traversal:

    O(n)


-------------------------------------------------------------------------------
SPACE COMPLEXITY
-------------------------------------------------------------------------------

O(1)

Only three counters are used.


===============================================================================
                                    CODE
===============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    // Input expression string
    string s;
    cin >> s;

    // Frequency counters
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;

    /*
        Traverse string and count numbers

        Ignore '+' characters
    */

    for(char ch : s) {

        if(ch == '1') count1++;

        else if(ch == '2') count2++;

        else if(ch == '3') count3++;
    }

    /*
        Build final sorted answer
    */

    vector<int> ans;

    // Add all 1s
    while(count1--) {

        ans.push_back(1);
    }

    // Add all 2s
    while(count2--) {

        ans.push_back(2);
    }

    // Add all 3s
    while(count3--) {

        ans.push_back(3);
    }

    /*
        Print numbers with '+'
    */

    for(int i = 0; i < ans.size(); i++) {

        cout << ans[i];

        // Avoid extra '+' at end
        if(i != ans.size() - 1) {

            cout << "+";
        }
    }

    return 0;
}