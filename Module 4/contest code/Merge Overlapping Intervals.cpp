// Merge Overlapping Intervals

// Problem Statement
// You are given an array of intervals. Your task is to merge all overlapping intervals and print them in sorted order of their start times.

// Input
// The first line contains an integer N — the number of intervals.
// Each of the next N lines contains two integers l and r — representing the endpoints of an interval [l, r], where l ≤ r.

// Output
// Print the merged intervals, each on a new line in the format l r, sorted by their start times.

// Constraints

// 1 ≤ N ≤ 10⁵

// −10⁹ ≤ l ≤ r ≤ 10⁹

// Example

// Input  1
// 3  
// 1 4  
// 3 5  
// 7 8  

// Output  1
// 1 5  
// 7 8  

// Input  2
// 2  
// -1 3  
// 5 8  

// Output  2
// -1 3  
// 5 8   


#include <bits/stdc++.h>
using namespace std;
     
int main() {
    int n; cin>>n;
    vector<pair<int,int>>v(n);
    for(int i=0;i<n;i++){
        int l,r; cin>>l>>r;
        v[i]={l,r};
    }
    sort(v.begin(),v.end());
    int end=-10e9;
    vector<pair<int,int>>result;
    for(int i=0;i<n;i++){
        int l=v[i].first;
        int r=v[i].second;
        if(l<=end){
            // overlap
            end=max(end,r);
            result[result.size()-1].second=end;
        }
        else{
            result.push_back({l,r});
        }
        end=max(end,r);
    }
    for(int i=0;i<result.size();i++){
        cout<<result[i].first<<" "<<result[i].second<<endl;
    }

    return 0;
}