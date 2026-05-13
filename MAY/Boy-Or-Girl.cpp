/*
===============================================================================
                        Codeforces - A. Boy or Girl
===============================================================================

QUESTION UNDERSTANDING
----------------------

We are given:
    A username string consisting of lowercase English letters.

Task:
    Count the number of DISTINCT characters.

Rules:

    If number of distinct characters is EVEN:
        print "CHAT WITH HER!"

    If number of distinct characters is ODD:
        print "IGNORE HIM!"


-------------------------------------------------------------------------------
EXAMPLE UNDERSTANDING
-------------------------------------------------------------------------------

Input:
    wjmzbmr

Distinct characters:

    w j m z b r

Count:
    6

6 is EVEN.

Output:
    CHAT WITH HER!


Another Example:

Input:
    xiaodao

Distinct characters:

    x i a o d

Count:
    5

5 is ODD.

Output:
    IGNORE HIM!


-------------------------------------------------------------------------------
CORE OBSERVATION
-------------------------------------------------------------------------------

The problem is actually about:

    Counting UNIQUE characters.

Repeated characters should only be counted once.


-------------------------------------------------------------------------------
NAIVE APPROACH
-------------------------------------------------------------------------------

One possible idea:

1. Maintain a list/vector
2. For every character:
        check if already present
3. If not present:
        add it
        increase count

This works.

But searching linearly every time can be slower.


-------------------------------------------------------------------------------
BETTER APPROACH - USING SET
-------------------------------------------------------------------------------

In C++:

    set

stores only UNIQUE values automatically.

Example:

    set<char> st;

When we insert characters:

    st.insert(ch);

Duplicate characters are ignored automatically.


-------------------------------------------------------------------------------
WHY SET WORKS
-------------------------------------------------------------------------------

Example:

Input:
    sevenkplus

Insert sequence:

    s
    e
    v
    e
    n
    k
    p
    l
    u
    s

Set stores only unique characters:

    s e v n k p l u

Count:
    8


-------------------------------------------------------------------------------
IMPORTANT OBSERVATION
-------------------------------------------------------------------------------

The actual logic of the problem is:

    ODD distinct count  -> IGNORE HIM!
    EVEN distinct count -> CHAT WITH HER!

This is a parity problem:
    odd/even checking.


-------------------------------------------------------------------------------
APPROACH
-------------------------------------------------------------------------------

1. Traverse the string
2. Insert every character into a set
3. Count distinct characters using set size
4. Check odd/even
5. Print answer


-------------------------------------------------------------------------------
DRY RUN
-------------------------------------------------------------------------------

Input:
    abaac

Insert into set:

    a
    b
    a (ignored)
    a (ignored)
    c

Set contains:

    a b c

Distinct count:
    3

3 is odd.

Output:
    IGNORE HIM!


-------------------------------------------------------------------------------
IMPORTANT LEARNING
-------------------------------------------------------------------------------

This problem teaches:

    Distinct Element Counting

Very common in CP.

Whenever you see:
    unique values
    distinct characters
    duplicate removal

think:
    set
    unordered_set
    frequency array


-------------------------------------------------------------------------------
PATTERN RECOGNITION
-------------------------------------------------------------------------------

This problem belongs to:

    1. Strings
    2. Sets
    3. Distinct Counting
    4. Parity Checking

Common CP Pattern:
    Count unique elements efficiently.


-------------------------------------------------------------------------------
TIME COMPLEXITY
-------------------------------------------------------------------------------

Each insertion in set:

    O(log n)

Total:

    O(n log n)

Since string length <= 100,
this is easily acceptable.


-------------------------------------------------------------------------------
SPACE COMPLEXITY
-------------------------------------------------------------------------------

At most 26 lowercase characters:

    O(1)


===============================================================================
                                    CODE
===============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    // Input username
    string s;
    cin >> s;

    /*
        Set stores only UNIQUE characters automatically
    */

    set<char> st;

    // Insert every character into set

    for(char ch : s) {

        st.insert(ch);
    }

    // Count distinct characters

    int distinctCount = st.size();

    /*
        If distinct count is even:
            CHAT WITH HER!

        Else:
            IGNORE HIM!
    */

    if(distinctCount % 2 == 0) {

        cout << "CHAT WITH HER!";
    }
    else {

        cout << "IGNORE HIM!";
    }

    return 0;
}