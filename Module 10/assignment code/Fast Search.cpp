/*
Task 1: Fast Search
Problem Statement:
 You are given an array a of n integers a₁, a₂, ..., aₙ.
 Your task is to respond to multiple queries of the form:
 "How many numbers in the array are between l and r (inclusive)?"
Input:
The first line contains an integer n (1 ≤ n ≤ 10⁵) – the length of the array.
The second line contains n integers a₁, a₂, ..., aₙ (-10⁹ ≤ aᵢ ≤ 10⁹).
The third line contains an integer k (1 ≤ k ≤ 10⁵) – the number of queries.
The next k lines each contain two integers l and r (-10⁹ ≤ l ≤ r ≤ 10⁹).
Output:
Print k integers – the results of each query.
Example:
 📌 Input:
5  
10 1 10 3 4  
4  
1 10  
2 9  
3 4  
2 2  

📌 Output:
5  
2  
2  
0  
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long


int main()
{
    ll in,n,m,i,j,k,x,y;
    cin>>n;
    vector<ll> v(n);
    for(i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    cin>>k;
    for(i=0;i<k;i++){
        ll l,r;
        cin>>l>>r;
        ll high=n,low=-1,mid1,mid2;
        while(high>low+1){
            mid1=(low+high)/2;
            if(v[mid1]>=l) high=mid1;
            else low=mid1;
        }
        mid1=low+1;

        high=n,low=-1;
        while(high>low+1){
            mid2=(low+high)/2;
            if(v[mid2]<=r) low=mid2;
            else high=mid2;
        }
        mid2=high-1;
        cout<<mid2-mid1+1<<" ";
    }
    
    return 0;
}