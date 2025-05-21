// **Check Anagram**

// **Problem Statement**
// You are given two strings A and B. Your task is to check whether the string B is an anagram of string $A$ or not.
// An **anagram** of a string is another string that contains the same characters, only the order of characters can be different. For example, “abcd” and “dabc” are anagrams of each other whereas "abcd" and "aabc" are not.

// ---

// **Input**
// The input consists of two lines:

// * The first line contains the string $A$.
// * The second line contains the string $B$.
//   Both strings contain only lowercase English letters.

// ---

// **Output**
// Print `"YES"` if string $B$ is an anagram of string $A$, otherwise print `"NO"`. (Print without quotation marks.)

// ---

// **Constraints**

// * $1 \leq |A|, |B| \leq 10000$
// * Strings contain only lowercase English letters (`a`–`z`).

// ---

// **Example 1**

// ```
// Input  
// abcd  
// dbac  

// Output  
// YES  
// ```

// **Example 2**

// ```
// Input  
// abcd  
// aabc  

// Output  
// NO  
// ```

// ---

// **Notes**
// To solve this problem, you can compare the frequency of characters in both strings or sort the strings and check if they are equal.


#include <iostream>
#include <string>
#include <vector>
using namespace std;

string are_anagrams(const string &a, const string &b) {
    if (a.size() != b.size()) return "NO";
    vector<int> freq(26, 0);

    for (char c : a) {
        freq[c - 'a']++;
    }

    for (char c : b) {
        freq[c - 'a']--;
    }

    for (int count : freq) {
        if (count != 0) {
            return "NO";
        }
    }

    return "YES";
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << are_anagrams(a, b) << endl;
    return 0;
}
