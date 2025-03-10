/*
Remove Adjacent Duplicates

বাং
Problem Statement
Given a string, remove all adjacent duplicates from it. The algorithm should continue removing adjacent duplicates from the string till no duplicate is present in the result.

For example, The input string is 'DBAABDAB'

The string left after the removal of all adjacent duplicates is 'AB'

'DBAABDAB' —> 'DBAABDAB' —> 'DBBDAB' —> 'DDAB' —> 'AB'
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
T test cases print the resulting string after removing all adjacent duplicates. Note that if the string becomes empty after removing adjacent duplicates print "-1".

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
10000
10000
S
S consists of upper case english letters only [A-Z]
Example 1:
Input:
2
DBAABDAB
OSTAD
Output:
AB
OSTAD
Example 2:
Input:
3
ABABABAB
ABABBABA
XABCCBAY
Output:
ABABABAB
-1
XY
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

string removeAdjacentDuplicates(string &s) {
    stack<char> st;
    
    for (char c : s) {
        if (!st.empty() && st.top() == c) {
            st.pop();
        } else {
            st.push(c);
        }
    }

    if (st.empty()) return "-1";

    string result = "";
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        string S;
        cin >> S;
        cout << removeAdjacentDuplicates(S) << "\n";
    }
    return 0;
}
