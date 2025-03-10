/*
Valid Bracket Sequence

বাং
Problem Statement
Given a string 
S
S containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Input
First line of the input contains an integer 
T
T, number of test cases.
Next 
T
T lines contains a string 
S
S.

Output
For each of the 
T
T string print "Valid" if the string is valid otherwise print "Not valid".

Constraints
1
1 
≤
≤ 
T
T 
≤
≤ 
100
100
1
1 
≤
≤ 
∣
S
∣
∣S∣ 
≤
≤ 
20000
20000
S
S consists of brackets only '()[]{}'.
Example 1:
Input:
2
[{()}]
[{(})]
Output:
Valid
Not valid
Example 2:
Input:
2
[{(
[]{}()[]
Output:
Not valid
Valid
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

bool isValidBracketSequence(string &s) {
    stack<char> st;
    unordered_map<char, char> matching = {{')', '('}, {']', '['}, {'}', '{'}};

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty() || st.top() != matching[c]) {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        string S;
        cin >> S;
        cout << (isValidBracketSequence(S) ? "Valid" : "Not valid") << "\n";
    }
    return 0;
}
