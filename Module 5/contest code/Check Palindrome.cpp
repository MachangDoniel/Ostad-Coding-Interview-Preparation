// **Check Palindrome**

// ---

// **Problem Statement**
// You are given a string $S$. Your task is to check whether the string is a palindrome or not.
// A palindrome is a string that reads the same backward as forward. For example, "z", "aaa", "aba", "abccba" are palindromes, but "ostad", "reality", "ab" are not.

// ---

// **Input**
// One line containing the string $S$, consisting only of lowercase English letters.

// ---

// **Output**
// Print **YES** if $S$ is a palindrome, otherwise print **NO**.

// ---

// **Constraints**

// * $1 \leq |S| \leq 50000$
// * $S$ contains only lowercase English letters $(a-z)$.

// ---

// **Example 1:**
// Input:

// ```
// madam
// ```

// Output:

// ```
// YES
// ```

// ---

// **Example 2:**
// Input:

// ```
// ostad
// ```

// Output:

// ```
// NO
// ```

// ---

// **Explanation:**
// Check if the string is the same when reversed. If yes, print YES; otherwise, print NO.


#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;
    
    int len = S.length();
    bool isPalindrome = true;
    
    // Check palindrome by comparing characters from both ends
    for (int i = 0; i < len / 2; i++) {
        if (S[i] != S[len - i - 1]) {
            isPalindrome = false;
            break;
        }
    }
    
    // Output result
    cout << (isPalindrome ? "YES" : "NO") << endl;

    return 0;
}
