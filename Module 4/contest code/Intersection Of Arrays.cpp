// Intersection Of Arrays

// Problem Statement
// You are given two arrays of integers of sizes N and M. Your task is to find the elements that appear in both arrays.

// Input
// The input consists of three lines:

// The first line contains two integers N and M.

// The second line contains N space-separated integers.

// The third line contains M space-separated integers.

// Output
// The output consists of two lines:

// The first line contains an integer S — the number of elements present in both arrays.

// The second line contains the S integers in ascending order.

// Constraints

// 1 ≤ N, M ≤ 10⁵

// Every integer in the arrays is between 0 and 10⁶

// Example


// Input  1
// 6 4  
// 1 2 3 4 5 6  
// 1 4 3 7  

// Output  1
// 3  
// 1 3 4  

// Input  2
// 3 5  
// 1 2 5  
// 9 2 2 5 5  

// Output  2
// 2  
// 2 5  
// Notes
// In the first example, the common elements are 1, 3, 4. They are printed in ascending order.


#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    set<int> setA, intersection;
    vector<int> result;

    // Read first array into a set
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        setA.insert(num);
    }

    // Read second array and check for intersection
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        if (setA.count(num)) { // If num is in setA, it's a common element
            intersection.insert(num);
        }
    }

    // Print the results
    cout << intersection.size() << endl;
    for (int num : intersection) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
