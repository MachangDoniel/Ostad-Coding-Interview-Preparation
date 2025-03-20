/*
Sort The Array 3

বাং
Problem Statement
You are given an array of integers of size 
N
N. You have to sort the array using Merge sort.

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

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void merge_sort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    merge_sort(arr, 0, n - 1);
    for (int ele : arr) {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}
