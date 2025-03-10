/*
Histogram

বাং
Problem Statement
A histogram is a graph that shows the frequency of numerical data using rectangles. The rectangles have equal widths but may have different heights. For example, the figure shows the histogram that consists of rectangles with the heights {2, 1, 4, 5, 1, 3, 3} measured in units where the width of the rectangles is 1.histogramNote that the order of the rectangles, i.e., their heights, is important. Calculate the area of the largest rectangle in a histogram that is aligned at the common base line, too. The figure on the right shows the largest aligned rectangle for the depicted histogram.

Input
Input starts with an integer 
T
T, denoting the number of test cases.

Each case contains a line with an integer 
N
N denoting the number of rectangles. The next line contains N space separated positive integers 
H
i
H 
i
​
  denoting the heights.

Output
For each case, print the area of the largest rectangle that can be made.

Constraints
1
1 
≤
≤ 
T
T 
≤
≤ 
100
100
1
1 
≤
≤ 
N
N 
≤
≤ 
10000
10000
1
1 
≤
≤ 
H
i
H 
i
​
  
≤
≤ 
10000
10000
Example 1:
Input:
2
7
2 1 4 5 1 3 3
5
4 4 3 2 4
Output:
8
10
Example 2:
Input:
2
5
1 1 10 1 1
2
9 13
Output:
10
18
*/

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    vector<int>heights(n);
    for(int i=0;i<n;i++){
        cin>>heights[i];
    }
    stack<int>st;
    int maxArea=0;
    for(int i=0;i<=n;i++){
        int h=(i==n)?0:heights[i];
        while(!st.empty() && heights[st.top()]>h){
            int idx1=st.top();
            int height=heights[idx1];
            st.pop();
            int width;
            if(!st.empty()) width=i-st.top()-1;
            else width=i;
            
            maxArea=max(maxArea,height*width);
        }
        st.push(i);
    }
    cout<<maxArea<<endl;
}

int main(){
    int t; cin>>t;
    while(t--){
        solve();
    }
}