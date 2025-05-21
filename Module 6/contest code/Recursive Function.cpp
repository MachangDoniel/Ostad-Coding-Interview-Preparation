// **Recursive Function**

// **Problem Statement**
// You are given an integer **N**. You have to compute the value of a function **f(N)**, where the function **f(x)** is defined for non-negative integers **x** as follows:

// * **f(0) = 1**
// * For all positive integers **k**,
//   **f(k) = f(⌊k / 2⌋) + f(⌊k / 3⌋)**

// Here, ⌊A⌋ denotes the value of **A** rounded down to the nearest integer (floor division).

// ---

// **Input**
// A single integer **N**.

// **Output**
// Output the value of **f(N)**.

// ---

// **Constraints**

// * 0 ≤ N ≤ 10¹⁸

// ---

// **Example 1**
// **Input:**

// ```
// 2
// ```

// **Output:**

// ```
// 3
// ```

// **Example 2**
// **Input:**

// ```
// 100
// ```

// **Output:**

// ```
// 55
// ```



#include <bits/stdc++.h>
using namespace std;

#define ll long long

map<ll,ll>mp;

ll call(ll k){
    if(k==0) return mp[k]=1;
    if(mp[k]==0){
         return mp[k]=call(k/2)+call(k/3);
    } 
    else return mp[k];
}

int main() {
    ll n;
    cin>>n;
    ll sum=call(n);
    cout<<sum<<endl;
    return 0;
}