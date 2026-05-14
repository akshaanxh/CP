/*
===============================================================================
                    Codeforces - A. Petya and Strings
===============================================================================

QUESTION UNDERSTANDING
----------------------

We are given two strings of equal length.

Task:
    Compare them lexicographically.

IMPORTANT:
    Uppercase and lowercase letters are considered SAME.

Meaning:

    'A' == 'a'
    'B' == 'b'

So:
    case does NOT matter.


-------------------------------------------------------------------------------
WHAT IS LEXICOGRAPHICAL COMPARISON?
-------------------------------------------------------------------------------

Lexicographical comparison is dictionary order comparison.

Example:

    abc < abd

because:
    first differing character:

        c < d


-------------------------------------------------------------------------------
OUTPUT RULES
-------------------------------------------------------------------------------

Print:

    -1 -> if first string is smaller
     1 -> if first string is greater
     0 -> if both strings are equal


-------------------------------------------------------------------------------
EXAMPLE UNDERSTANDING
-------------------------------------------------------------------------------

Input:
    aaaa
    aaaA

Ignoring case:

    aaaa
    aaaa

Both are equal.

Output:
    0


-------------------------------------------------------------------------------

Input:
    abs
    Abz

Convert both to lowercase:

    abs
    abz

Comparison:

    a == a
    b == b
    s < z

Therefore:

    first string is smaller

Output:
    -1


-------------------------------------------------------------------------------
CORE OBSERVATION
-------------------------------------------------------------------------------

Since case does not matter,
we should first:

    convert both strings to same case

Either:
    lowercase
or
    uppercase

Then compare normally.


-------------------------------------------------------------------------------
WHY CASE CONVERSION IS IMPORTANT
-------------------------------------------------------------------------------

ASCII values:

    'A' = 65
    'a' = 97

Without conversion:
    comparisons become incorrect.

So:
    normalize both strings first.


-------------------------------------------------------------------------------
APPROACH
-------------------------------------------------------------------------------

1. Read both strings
2. Convert both strings to lowercase
3. Compare strings lexicographically
4. Print:
        -1
         1
         0


-------------------------------------------------------------------------------
C++ SHORTCUT
-------------------------------------------------------------------------------

C++ strings support direct comparison.

Example:

    if(a < b)

This automatically performs
lexicographical comparison.


-------------------------------------------------------------------------------
DRY RUN
-------------------------------------------------------------------------------

Input:
    abcdefg
    AbCdEfF

Lowercase versions:

    abcdefg
    abcdeff

Compare:

    a == a
    b == b
    c == c
    d == d
    e == e
    f == f

At last character:

    g > f

So:
    first string is greater.

Output:
    1


-------------------------------------------------------------------------------
IMPORTANT LEARNING
-------------------------------------------------------------------------------

This problem teaches:

    1. Lexicographical comparison
    2. Case normalization
    3. ASCII/case handling
    4. String manipulation

Very common CP pattern:
    Normalize strings before comparison.


-------------------------------------------------------------------------------
PATTERN RECOGNITION
-------------------------------------------------------------------------------

This problem belongs to:

    1. Strings
    2. Lexicographical Comparison
    3. ASCII Manipulation
    4. Implementation


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

    // Input strings
    string a, b;

    cin >> a >> b;

    /*
        Convert both strings to lowercase
    */

    for(int i = 0; i < a.size(); i++) {

        a[i] = tolower(a[i]);
        b[i] = tolower(b[i]);
    }

    /*
        Lexicographical comparison
    */

    if(a < b) {

        cout << -1;
    }

    else if(a > b) {

        cout << 1;
    }

    else {

        cout << 0;
    }

    return 0;
}