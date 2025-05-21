// **No Equal Neighbour**

// **Problem Statement**
// You are given an integer **N**. You have to print all strings of length **N** such that:

// * The strings contain only the characters `'a'`, `'b'`, `'c'`. Some characters may be absent.
// * No two adjacent characters in the string are the same.
// * The output should be in **lexicographically increasing order**.

// A string **x** is lexicographically smaller than string **y** if either **x** is a prefix of **y** and **x ≠ y**, or at the first position **i** where they differ, **x\[i] < y\[i]**.

// **Input**
// A single integer **N** — the length of the strings to generate.

// **Output**
// Print all valid strings of length **N** in lexicographically increasing order.

// **Constraints**
// 1 ≤ N ≤ 15

// **Example 1**
// **Input:**

// ```
// 1
// ```

// **Output:**

// ```
// a
// b
// c
// ```

// **Example 2**
// **Input:**

// ```
// 2
// ```

// **Output:**

// ```
// ab
// ac
// ba
// bc
// ca
// cb
// ```

// **Example 3**
// **Input:**

// ```
// 3
// ```

// **Output:**

// ```
// aba
// abc
// aca
// acb
// bab
// bac
// bca
// bcb
// cab
// cac
// cba
// cbc
// ```


#include <bits/stdc++.h>
using namespace std;

void call(int n,string str,char ch){
    if(n==0){
        cout<<str<<endl;
        return;
    }
    if(ch!='a') call(n-1,str+'a','a');
    if(ch!='b') call(n-1,str+'b','b');
    if(ch!='c') call(n-1,str+'c','c');

}

int main() {
    int n; cin>>n;
    call(n,"",'x');
    return 0;
}