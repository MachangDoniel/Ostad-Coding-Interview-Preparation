// Stairs
// https://www.interviewbit.com/problems/stairs/

// You are climbing a stair case and it takes A steps to reach to the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?



// Input Format:

// The first and the only argument contains an integer A, the number of steps.
// Output Format:

// Return an integer, representing the number of ways to reach the top.
// Constrains:

// 1 <= A <= 36
// Example :

// Input 1:

// A = 2 Output 1:

// 2 Explanation 1:

// [1, 1], [2] Input 2:

// A = 3 Output 2:

// 3 Explanation 2: 

// [1 1 1], [1 2], [2 1]


// Solution 1: without memoization
// module.exports = { 
//  //param A : integer
//  //return an integer
// 	climbStairs : function(A){
//         if(A==1 || A==2) return A;
//         return this.climbStairs(A-1) + this.climbStairs(A-2);
// 	}
// };

// Solution 2: using memoization
const memo = [];

module.exports = { 
 //param A : integer
 //return an integer
	climbStairs : function(A){
        if(memo[A]) return memo[A];
        if(A==1 || A==2) return memo[A] = A;
        return memo[A] = this.climbStairs(A-1) + this.climbStairs(A-2);
	}
};




// 🚀 In the climbStairs(n) problem:
// 🔁 Naive Recursive Time Complexity:
// 𝑇(𝑛)=𝑇(𝑛−1)+𝑇(𝑛−2)   (similar to Fibonacci)
// So:

// T(30) ≈ 1 million calls

// T(40) ≈ 100 million calls

// T(45+) → already unusable without memoization

// 📌 Threshold where memoization becomes necessary:
// For n > 30, naive recursion becomes noticeably slow

// For n ≥ 40, it's almost unusable without memoization or bottom-up DP