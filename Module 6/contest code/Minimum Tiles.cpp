// **Minimum Tiles**

// **Problem Statement**
// You are given two integers **N** and **M**. You want to tile a room of size **N × M**. You have an infinite number of square tiles of size **2^i × 2^i**, where **i = 0, 1, 2, ...**.
// Your task is to find the **minimum number of tiles** required to completely fill the room.

// **Input**
// Two integers **N** and **M** — the dimensions of the room.

// **Output**
// Print a single integer — the minimum number of tiles needed.

// **Constraints**
// 1 ≤ N, M ≤ 10⁹

// **Example 1**
// **Input:**

// ```
// 5 6
// ```

// **Output:**

// ```
// 9
// ```

// **Example 2**
// **Input:**

// ```
// 4 11
// ```

// **Output:**

// ```
// 8
// ```


#include <bits/stdc++.h>
using namespace std;


int findMinCell(int n,int m){
    int minCell=min(n,m);
    int power=31;
    while(minCell<pow(2,power)){
        power--;
    }
    return pow(2,power);
}

int call(int n,int m){
    if(n==0 || m==0) return 0;
    // cout<<n<<" "<<m<<endl;
    int cell=findMinCell(n,m);
    int nn=max(n,m);
    int mm=min(n,m);
    n=nn,m=mm;
    int div=n/cell;
    nn%=cell,mm%=cell;
    return call(n-nn,mm) + call(nn,m-mm) + call(nn,mm) + div;
}

int main() {
    int n,m; cin>>n>>m;
    cout<<call(n,m)<<endl;
    return 0;
}