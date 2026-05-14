/*
===============================================================================
                Codeforces - A. Word Capitalization
===============================================================================

QUESTION UNDERSTANDING
----------------------

We are given a word.

Task:
    Capitalize ONLY the first letter of the word.

Important:
    All remaining letters must remain unchanged.


-------------------------------------------------------------------------------
WHAT DOES CAPITALIZATION MEAN?
-------------------------------------------------------------------------------

Capitalization means:

    First letter becomes uppercase.

Examples:

    apple  -> Apple
    hello  -> Hello
    world  -> World


-------------------------------------------------------------------------------
IMPORTANT NOTE
-------------------------------------------------------------------------------

ONLY the first character changes.

All other characters stay exactly the same.

Example:

Input:
    ApPLe

Output:
    ApPLe

Because:
    first character is already uppercase.


-------------------------------------------------------------------------------
EXAMPLE UNDERSTANDING
-------------------------------------------------------------------------------

Input:
    konjac

First character:
    k

Uppercase version:
    K

Final Output:
    Konjac


-------------------------------------------------------------------------------
CORE OBSERVATION
-------------------------------------------------------------------------------

We only need to modify:

    s[0]

The rest of the string remains unchanged.


-------------------------------------------------------------------------------
APPROACH
-------------------------------------------------------------------------------

1. Read string
2. Convert first character to uppercase
3. Print modified string


-------------------------------------------------------------------------------
C++ FUNCTION USED
-------------------------------------------------------------------------------

C++ provides:

    toupper()

It converts lowercase letters into uppercase.

Example:

    toupper('a') -> 'A'

If character is already uppercase:
    it remains unchanged.


-------------------------------------------------------------------------------
ASCII INSIGHT
-------------------------------------------------------------------------------

Internally:

    'a' = 97
    'A' = 65

Difference:
    32

But:
    using toupper() is cleaner and safer.


-------------------------------------------------------------------------------
DRY RUN
-------------------------------------------------------------------------------

Input:
    codeforces

s[0]:
    c

toupper(c):
    C

Final string:
    Codeforces


-------------------------------------------------------------------------------
IMPORTANT LEARNING
-------------------------------------------------------------------------------

This problem teaches:

    Direct String Manipulation

Very common beginner CP pattern:
    modify characters using indices.


-------------------------------------------------------------------------------
PATTERN RECOGNITION
-------------------------------------------------------------------------------

This problem belongs to:

    1. Strings
    2. Character Manipulation
    3. ASCII / Case Conversion
    4. Implementation

Common CP Pattern:
    Access and modify specific characters.


-------------------------------------------------------------------------------
TIME COMPLEXITY
-------------------------------------------------------------------------------

Only one operation:

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

    // Input string
    string s;
    cin >> s;

    /*
        Convert first character
        into uppercase
    */

    s[0] = toupper(s[0]);

    // Print modified string
    cout << s;

    return 0;
}