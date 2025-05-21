// **Shortest Palindrome**

// **Problem Statement**
// You are given a string $S$. You can add some characters at the **beginning** of the string. Your task is to create the **shortest palindrome** by adding some (possibly none) characters at the beginning of $S$.

// A **palindrome** is a string that reads the same backward as forward, for example, "z", "aaa", "aba", "abccba" are palindromes, but "ostad", "reality", "ab" are not.

// ---

// **Examples**

// * If the input string is `"bcba"`, the shortest palindrome by adding characters at the beginning is `"abcba"`.
// * If the input string is `"abcba"`, the shortest palindrome is `"abcba"` itself (no characters need to be added).
// * If the input string is `"abcd"`, the shortest palindrome is `"dcbabcd"`.

// ---

// **Input**
// A single line containing the string $S$, consisting of only lowercase English letters.

// ---

// **Output**
// Print the shortest palindrome that can be formed by adding characters only at the beginning of $S$.

// ---

// **Constraints**

// * $1 \leq |S| \leq 100000$
// * $S$ contains only lowercase English letters (`a`-`z`).

// ---

// **Example 1**

// ```
// Input  
// bcba  

// Output  
// abcba  
// ```

// **Example 2**

// ```
// Input  
// abcba  

// Output  
// abcba  
// ```

// **Example 3**

// ```
// Input  
// abcd  

// Output  
// dcbabcd  
// ```

// ---

// **Notes**
// To solve the problem efficiently, one can use algorithms like KMP (Knuth-Morris-Pratt) to find the longest palindromic prefix and then add the minimum required characters at the front.


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


string shortest_palindrome(string s) {
    int n = s.size();
    string reversed_s = s;
    reverse(reversed_s.begin(), reversed_s.end());

    for (int i = 0; i < n; ++i) {
        if (s.substr(0, n - i) == reversed_s.substr(i)) {
            return reversed_s.substr(0, i) + s;
        }
    }

    return reversed_s + s;
}

int main() {
    string s;
    cin >> s;
    cout << shortest_palindrome(s) << endl;
    return 0;
}
