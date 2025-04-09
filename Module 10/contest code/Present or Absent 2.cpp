/*
Present or Absent 2

বাং
Problem Statement
You are given a non decreasing array of integers of size 
N
N and a range 
[
L
,
R
]
[L,R]. You have to determine if there is a number between 
[
L
,
R
]
[L,R] is present in the array or absent .

Input
The input consists of two lines. First one having three integers 
N
N , 
L
L and 
R
R. Next line contains 
N
N integers.

Output
Print P if there is a number between 
[
L
,
R
]
[L,R] is present in the array or print A if it is absent.

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
L
L 
≤
≤ 
R
R 
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
5 1 10
3 8 10 10 14
Output:
P
Example 2:
Input:
3 2 5
-1 0 1
Output:
A
*/

// Runtime: 12.95 ms
#include <bits/stdc++.h>
using namespace std;
     
int main() {
    int n,l,r; cin>>n>>l>>r;
    vector<int>v(n);
    bool flag=false;
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(l<=v[i] && v[i]<=r) flag=true;
    }
    flag?cout<<"P":cout<<"A";
    cout<<endl;
    
    return 0;
}

// Runtime: 12.75 ms
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,l,r; cin>>n>>l>>r;
    vector<int>v(n);
    bool flag=false;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int low=-1,high=n;
    while(high>low+1){
        int mid=(high+low)/2;
        if(l<=v[mid] && v[mid]<=r){
            cout<<"P"<<endl;
            return 0;
        }
        else if(l<=v[mid]) high=mid; //v[mid]>r
        else low=mid;              //v[mid]<l
    }
    cout<<"A"<<endl;
    
    return 0;
}

// Runtime: 13.05 ms
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,l,r; cin>>n>>l>>r;
    vector<int>v(n);
    bool flag=false;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int low=0,high=n-1;
    while(high>=low){
        int mid=(high+low)/2;
        if(l<=v[mid] && v[mid]<=r){
            cout<<"P"<<endl;
            return 0;
        }
        else if(l<=v[mid]) high=mid-1; //v[mid]>r
        else low=mid+1;              //v[mid]<l
    }
    cout<<"A"<<endl;
    
    return 0;
}