/*
Sort The Array

বাং
Problem Statement
You are given an array of integers of size 
N
N. You have to sort the array using bubble sort.

Input
The input consists of two lines. First one having one integer 
N
N. Next line contains 
N
N integers.

Output
Print the after sorting.

Constraints
1 
≤
≤ N 
≤
≤ 1000
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
5
10 8 14 3 10
Output:
3 8 10 10 14
Example 2:
Input:
3
1 -1 0
Output:
-1 0 1
*/

#include <bits/stdc++.h>
using namespace std;

void Swap(int &a,int &b){
    int temp=a;
    a=b,b=temp;
}

void bubble_sort(vector<int>&a){
    int n=a.size();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                Swap(a[j],a[j+1]);
            }
        }
    }
}

int main() {
    int n; cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    bubble_sort(a);
    for(int ele:a){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}