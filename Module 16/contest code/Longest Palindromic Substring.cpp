// Longest Palindromic Substring
// 📝 Problem Statement
// You are given a string of length N. Your task is to find the length of the longest palindromic substring of the given string.

// 📥 Input Format
// First line: An integer N — the length of the string

// Second line: A string S of length N, consisting of lowercase English letters

// 📤 Output Format
// Print one integer: the length of the longest palindromic substring of S

// 🔒 Constraints
// 1 ≤ N ≤ 1000

// All characters in the string are lowercase Latin letters (a to z)

// 💡 Example 1
// Input:

// Copy
// Edit
// 5
// abcbx
// Output:

// Copy
// Edit
// 3
// Explanation:
// The longest palindromic substring is "bcb", which has a length of 3.

// 💡 Example 2
// Input:

// Copy
// Edit
// 3
// abc
// Output:

// Copy
// Edit
// 1
// Explanation:
// Each individual character is a palindrome. So the maximum length is 1.


#include <iostream>
#include <string>
using namespace std;

int expandFromCenter(const string &s, int left, int right) {
    int n = s.size();
    while (left >= 0 && right < n && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1; // Length of the palindrome
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    int maxLength = 1;
    for (int i = 0; i < n; ++i) {
        int len1 = expandFromCenter(s, i, i);     // Odd length
        int len2 = expandFromCenter(s, i, i + 1); // Even length
        maxLength = max(maxLength, max(len1, len2));
    }

    cout << maxLength << endl;
    return 0;
}
