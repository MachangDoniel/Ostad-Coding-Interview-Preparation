/*
Present or Absent

বাং
Problem Statement
You are given an non decreasing array of integers of size 
N
N and an integer 
X
X. You have to determine if 
X
X is present in the array or absent .

Input
The input consists of two lines. First one having two integers 
N
N and 
X
X. Next line contains 
N
N integers.

Output
Print P if 
X
X is present in the array or print A if it is absent.

Constraints
1 
≤
≤ 
N
N 
≤
≤ 
1
0
5
10 
5
 
−
1
0
9
−10 
9
  
≤
≤ 
X
X 
≤
≤ 
1
0
9
10 
9
 
Every integer of the array is between 
−
1
0
9
−10 
9
  and 
1
0
9
10 
9
 
Example 1:
Input:
5 10
3 8 10 10 14
Output:
P
Example 2:
Input:
3 2
-1 0 1
Output:
A
*/

// Runtime 12.45 ms
#include <bits/stdc++.h>
using namespace std;
     
int main() {
    int n,x; cin>>n>>x;
    vector<int>v(n);
    bool flag=false;
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(x==v[i]) flag=true;
    }
    flag?cout<<"P":cout<<"A";
    cout<<endl;
    
    return 0;
}

// Runtime: 13 ms
#include <bits/stdc++.h>
using namespace std;
     
int main() {
    int n,x; cin>>n>>x;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int low=-1,high=n;
    while(high>low+1){
        int mid=(high+low)/2;
        if(x==v[mid]){
            cout<<"P"<<endl;
            return 0;
        }
        else if(x<v[mid]) high=mid; //v[mid]>x
        else low=mid;              //v[mid]<x
    }
    cout<<"A"<<endl;
    
    return 0;
}