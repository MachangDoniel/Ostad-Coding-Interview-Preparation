// Longest Increasing Subsequence
// link: https://www.interviewbit.com/problems/longest-increasing-subsequence/

// Problem Description
 
 

// Find the longest increasing subsequence of a given array of integers, A.

// In other words, find a subsequence of array in which the subsequence's elements are in strictly increasing order, and in which the subsequence is as long as possible.

// In this case, return the length of the longest increasing subsequence.



// Problem Constraints
// 1 <= length(A) <= 2500

// 0 <= A[i] <= 2500



// Input Format
// The first and the only argument is an integer array A.



// Output Format
// Return an integer representing the length of the longest increasing subsequence.



// Example Input
// Input 1:

//  A = [1, 2, 1, 5]
// Input 2:

//  A = [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]


// Example Output
// Output 1:

//  3
// Output 2:

//  6


// Example Explanation
// Explanation 1:

//  The longest increasing subsequence: [1, 2, 5]
// Explanation 2:

//  The possible longest increasing subsequences: [0, 2, 6, 9, 13, 15] or [0, 4, 6, 9, 11, 15] or [0, 4, 6, 9, 13, 15]


// Solution O(n^2)
module.exports = { 
 //param A : array of integers
 //return an integer
    lis : function(A){
        const n = A.length;
        // console.log("n: "+n);
        const dp=new Array(n).fill(1);
        for(let i=0;i<n;i++){
            for(let j=0;j<i;j++){
                if(A[i]>A[j]){
                    dp[i]=Math.max(dp[i],dp[j]+1);
                }
            }
        }
        return Math.max(...dp);
    }
};

// // Solution O(n^2) with print the LIS

module.exports = {
  // param A: array of integers
  // return an integer
  lis: function (A) {
    const n = A.length;
    const dp = new Array(n).fill(1);         // dp[i]: LIS length ending at i
    const parent = new Array(n).fill(-1);    // parent[i]: previous index in LIS ending at i

    let maxLen = 1;
    let maxIndex = 0;

    for (let i = 0; i < n; i++) {
      for (let j = 0; j < i; j++) {
        if (A[i] > A[j] && dp[i] < dp[j] + 1) {
          dp[i] = dp[j] + 1;
          parent[i] = j;  // track the predecessor
        }
      }
      if (dp[i] > maxLen) {
        maxLen = dp[i];
        maxIndex = i;
      }
    }

    // Reconstruct LIS sequence
    const sequence = [];
    let current = maxIndex;
    while (current !== -1) {
      sequence.push(A[current]);
      current = parent[current];
    }
    sequence.reverse();

    // console.log(sequence);

    return maxLen;
  }
};



// Solution: O(nlogn)

module.exports = {
  // param A: array of integers
  // return an integer
  lis: function(A) {
    if (A.length === 0) return 0;

    const tails = [];

    for (let num of A) {
      let left = 0, right = tails.length;

      // Binary search to find the position to replace
      while (left < right) {
        let mid = Math.floor((left + right) / 2);
        if (tails[mid] < num) {
          left = mid + 1;
        } else {
          right = mid;
        }
      }

      tails[left] = num;
    }

    return tails.length;
  }
};

// tails[i] represents the smallest possible last element (tail) of an increasing subsequence of length i + 1.
// It's not the actual subsequence — just enough to track potential LIS lengths efficiently.
