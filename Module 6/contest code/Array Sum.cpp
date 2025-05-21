// **Array Sum**

// **Problem Statement**
// You are given an integer **S**. Your task is to find the number of arrays consisting of **positive integers** such that the **sum of the elements is equal to S**.

// For example, if **S = 3**, there are **4** such arrays:

// * \[1, 1, 1]
// * \[1, 2]
// * \[2, 1]
// * \[3]

// Note that the **order of elements matters** (i.e., \[1,2] and \[2,1] are considered different).

// ---

// **Input**
// A single integer **S** — the target sum.

// **Output**
// An integer — the number of arrays of positive integers whose sum is **S**.

// ---

// **Constraints**
// 1 ≤ S ≤ 20

// ---

// **Example 1**
// **Input:**

// ```
// 3
// ```

// **Output:**

// ```
// 4
// ```

// **Example 2**
// **Input:**

// ```
// 4
// ```

// **Output:**

// ```
// 8
// ```


#include <bits/stdc++.h>
using namespace std;
     
int call(int sumRest){
    if(sumRest==0) return 1;
    int count=0;
    for(int i=1;i<=sumRest;i++){
        count+=call(sumRest-i);
    }
    return count;
}

int main() {
    int sum; cin>>sum;
    cout<<call(sum)<<endl;
    return 0;
}