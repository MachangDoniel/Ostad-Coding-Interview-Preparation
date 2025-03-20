/*
Sort The Array 4

বাং
Problem Statement
You are given an array of integers of size 
N
N. You have to sort the array using Counting sort.

Note: Using other sorting algorithms may lead to TLE.

Input
Input consists of two lines. First one having one integer 
N
N. Next line contains 
N
N integers.

Output
Print the array after sorting .

Constraints
1
1 
≤
≤ 
N
N 
≤
≤ 
1
0
6
10 
6
 
Every integer of the array is between 
1
1 and 
1
0
6
10 
6
 
Example 1:
Input:
5
10 8 14 3 10
Output:
3 8 10 10 14
Example 2:
Input:
3
1 4 2
Output:
1 2 4 
*/

#include <bits/stdc++.h>
using namespace std;

void counting_sort(vector<int>& arr) {
    int max_val = *max_element(arr.begin(), arr.end());
    vector<int> count(max_val + 1, 0);
    
    for (int num : arr) {
        count[num]++;
    }
    
    int index = 0;
    for (int i = 0; i <= max_val; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    counting_sort(arr);
    for (int ele : arr) {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}