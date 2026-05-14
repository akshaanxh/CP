/*
===============================================================================
                    CSES - Palindrome Reorder
===============================================================================

QUESTION UNDERSTANDING
----------------------

We are given a string consisting of uppercase letters:

    A-Z

Task:
    Rearrange the letters so that the string becomes a palindrome.

A palindrome reads same:
    forward and backward.

Examples:

    ABA
    ABCCBA
    AACABACAA


If no palindrome can be formed:
    print "NO SOLUTION"


-------------------------------------------------------------------------------
WHAT IS A PALINDROME?
-------------------------------------------------------------------------------

In a palindrome:

    Left side mirrors right side.

Example:

        A B C B A
        | | | | |
        A B C B A

So:
    characters must appear symmetrically.


-------------------------------------------------------------------------------
CORE OBSERVATION
-------------------------------------------------------------------------------

Frequency of characters determines whether
a palindrome is possible.


-------------------------------------------------------------------------------
CASE 1 - EVEN LENGTH STRING
-------------------------------------------------------------------------------

Example length:
    8

Every character must appear EVEN number of times.

Why?

Because every occurrence needs a matching pair.

Example:

    A _ _ _ _ _ _ A


-------------------------------------------------------------------------------
CASE 2 - ODD LENGTH STRING
-------------------------------------------------------------------------------

Example length:
    9

Exactly ONE character may have odd frequency.

Why?

Because middle character does not need a pair.

Example:

    A A C A B A C A A
            ^
          middle


-------------------------------------------------------------------------------
FINAL PALINDROME CONDITION
-------------------------------------------------------------------------------

A palindrome is possible IF:

    At most ONE character has odd frequency.


-------------------------------------------------------------------------------
EXAMPLE UNDERSTANDING
-------------------------------------------------------------------------------

Input:
    AAAACACBA

Frequencies:

    A -> 6
    B -> 1
    C -> 2

Only one character has odd frequency:
    B

So palindrome is possible.


-------------------------------------------------------------------------------
HOW TO CONSTRUCT PALINDROME
-------------------------------------------------------------------------------

Main idea:

    left + middle + reverse(left)

Steps:

1. Put half of every character in left part
2. Put odd frequency character in middle
3. Mirror left part to create right part


-------------------------------------------------------------------------------
CONSTRUCTION DRY RUN
-------------------------------------------------------------------------------

Input:
    AAAACACBA

Frequencies:

    A -> 6
    B -> 1
    C -> 2


Build LEFT half:

    A contributes 3 -> AAA
    C contributes 1 -> C

Left:
    AAAC

Middle:
    B

Right:
    CAAA

Final palindrome:

    AAACBCAAA


-------------------------------------------------------------------------------
WHY FREQUENCY ARRAY?
-------------------------------------------------------------------------------

Characters are only:

    A-Z

So we use:

    int freq[26]

instead of map/unordered_map.

Faster and simpler.


-------------------------------------------------------------------------------
APPROACH
-------------------------------------------------------------------------------

1. Count frequencies
2. Count odd frequency characters
3. If more than one odd:
        print NO SOLUTION
4. Otherwise:
        build left half
        build middle
        mirror left half
5. Print palindrome


-------------------------------------------------------------------------------
IMPORTANT LEARNING
-------------------------------------------------------------------------------

This problem teaches:

    1. Frequency Counting
    2. Palindrome Properties
    3. Greedy Construction
    4. String Building

Very common CP observation:
    palindrome problems are often frequency based.


-------------------------------------------------------------------------------
PATTERN RECOGNITION
-------------------------------------------------------------------------------

This problem belongs to:

    1. Strings
    2. Frequency Counting
    3. Greedy Construction
    4. Palindrome Properties

Common CP Pattern:
    Use frequency symmetry to build strings.


-------------------------------------------------------------------------------
TIME COMPLEXITY
-------------------------------------------------------------------------------

Single traversal + construction:

    O(n)


-------------------------------------------------------------------------------
SPACE COMPLEXITY
-------------------------------------------------------------------------------

O(1)

Frequency array size is fixed (26).


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
        Frequency array for A-Z
    */

    int freq[26] = {0};

    // Count frequencies

    for(char ch : s) {

        freq[ch - 'A']++;
    }

    /*
        Count odd frequency characters
    */

    int oddCount = 0;

    for(int i = 0; i < 26; i++) {

        if(freq[i] % 2 != 0) {

            oddCount++;
        }
    }

    /*
        More than one odd frequency
        means palindrome impossible
    */

    if(oddCount > 1) {

        cout << "NO SOLUTION";
        return 0;
    }

    // Stores left half
    string left = "";

    // Stores middle character(s)
    string middle = "";

    /*
        Build palindrome parts
    */

    for(int i = 0; i < 26; i++) {

        char ch = i + 'A';

        /*
            Add half frequency to left side
        */

        left += string(freq[i] / 2, ch);

        /*
            Odd frequency character
            goes to middle
        */

        if(freq[i] % 2 != 0) {

            middle += string(freq[i] % 2, ch);
        }
    }

    /*
        Right side is reverse of left side
    */

    string right = left;

    reverse(right.begin(), right.end());

    // Final palindrome

    cout << left + middle + right;

    return 0;
}