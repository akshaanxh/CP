/*
===============================================================================
                Codeforces - A. Ultra-Fast Mathematician
===============================================================================

QUESTION UNDERSTANDING
----------------------

We are given two binary strings.

Binary strings contain only:
    0 and 1

Task:
    Create a new binary string such that:

    If digits at same position are DIFFERENT:
        result digit = 1

    If digits at same position are SAME:
        result digit = 0


-------------------------------------------------------------------------------
IMPORTANT OBSERVATION
-------------------------------------------------------------------------------

This is exactly the definition of:

    XOR operation

XOR Truth Table:

    A   B   A XOR B

    0   0      0
    0   1      1
    1   0      1
    1   1      0

Notice:

    SAME digits      -> 0
    DIFFERENT digits -> 1

Exactly matches the problem statement.


-------------------------------------------------------------------------------
EXAMPLE UNDERSTANDING
-------------------------------------------------------------------------------

Input:
    1010100
    0100101

Position-wise comparison:

    1 vs 0 -> 1
    0 vs 1 -> 1
    1 vs 0 -> 1
    0 vs 0 -> 0
    1 vs 1 -> 0
    0 vs 0 -> 0
    0 vs 1 -> 1

Result:

    1110001


-------------------------------------------------------------------------------
APPROACH
-------------------------------------------------------------------------------

1. Traverse both strings simultaneously
2. Compare characters at same index
3. If same:
        append '0'
4. Else:
        append '1'
5. Print final string


-------------------------------------------------------------------------------
WHY STRING TRAVERSAL?
-------------------------------------------------------------------------------

Input length can be up to:
    100 digits

Numbers may also contain leading zeros.

So:
    treating input as strings is simpler and safer.


-------------------------------------------------------------------------------
ALTERNATIVE XOR THINKING
-------------------------------------------------------------------------------

Another way:

Convert characters into integers and apply XOR.

Example:

    (a[i]-'0') ^ (b[i]-'0')

But direct character comparison is cleaner here.


-------------------------------------------------------------------------------
DRY RUN
-------------------------------------------------------------------------------

Input:
    1110
    1010

Comparisons:

    1 vs 1 -> 0
    1 vs 0 -> 1
    1 vs 1 -> 0
    0 vs 0 -> 0

Output:
    0100


-------------------------------------------------------------------------------
IMPORTANT LEARNING
-------------------------------------------------------------------------------

This problem teaches:

    XOR observation

Very common CP pattern:

    SAME      -> 0
    DIFFERENT -> 1

immediately suggests XOR.


-------------------------------------------------------------------------------
PATTERN RECOGNITION
-------------------------------------------------------------------------------

This problem belongs to:

    1. Strings
    2. Bit Manipulation
    3. XOR Logic
    4. Simulation

Common CP Pattern:
    Perform operations digit-by-digit.


-------------------------------------------------------------------------------
TIME COMPLEXITY
-------------------------------------------------------------------------------

Single traversal of string:

    O(n)


-------------------------------------------------------------------------------
SPACE COMPLEXITY
-------------------------------------------------------------------------------

O(n)
for storing answer string.


===============================================================================
                                    CODE
===============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    // Input binary strings
    string a, b;
    cin >> a >> b;

    // Stores final XOR result
    string ans = "";

    /*
        Traverse both strings simultaneously
    */

    for(int i = 0; i < a.size(); i++) {

        /*
            If characters are same:
                append 0

            Else:
                append 1
        */

        if(a[i] == b[i]) {

            ans += '0';
        }
        else {

            ans += '1';
        }
    }

    // Print final answer
    cout << ans;

    return 0;
}