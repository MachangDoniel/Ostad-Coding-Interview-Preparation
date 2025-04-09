/*
Problem Statement:
 Given an array of n numbers, sorted in non-decreasing order, and k queries,
 for each query, find the maximum index of an element not greater than the given value.
Input:
The first line contains n and k (0 < n, k ≤ 10⁵).
The second line contains n integers in sorted order.
The third line contains k queries.
All values are integers with absolute values ≤ 2 × 10⁹.
Output:
For each query, print the maximum index (1-based) of the element ≤ the given number.
If no such element exists, print 0.
Example:
 📌 Input:
5 5  
3 3 5 8 9  
2 4 8 1 10  

📌 Output:
0  
2  
4  
0  
5  
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
 

int main()
{
    ll in,n,m,i,j,k,x,y;
    cin>>n>>k;
    vector<ll> v(n);
    for(i=0;i<n;i++){
        cin>>v[i];
    }
    for(i=0;i<k;i++){
        cin>>in;
        ll high=n,low=-1,mid;
        while(high>low+1){
            mid=(high+low)/2;
            if(v[mid]>in) high=mid;
            else low=mid;
        }
        cout<<low+1<<endl;
    }
    return 0;
}