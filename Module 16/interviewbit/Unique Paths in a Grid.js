// Unique Paths in a Grid
// https://www.interviewbit.com/problems/unique-paths-in-a-grid/

// Given a grid of size m * n, lets assume you are starting at (1,1) and your goal is to reach (m,n). At any instance, if you are on (x,y), you can either go to (x, y + 1) or (x + 1, y).

// Now consider if some obstacles are added to the grids. How many unique paths would there be?

// An obstacle and empty space is marked as 1 and 0 respectively in the grid.

// Example :

// There is one obstacle in the middle of a 3x3 grid as illustrated below.

// [
//   [0,0,0],
//   [0,1,0],
//   [0,0,0]
// ]
// The total number of unique paths is 2.

// Note: m and n will be at most 100.


// solution: O(n^2)
module.exports = { 
  uniquePathsWithObstacles: function(A) {
    const m=A.length;
    const n=A[0].length;

    if(A[0][0]===1 || A[m-1][n-1]===1) return 0;

    const dp=Array.from({length:m},() => new Array(n).fill(0));
    dp[0][0]=1;

    for(let i=1;i<m;i++){
      if(A[i][0]===0) dp[i][0]=dp[i-1][0];
    }

    for(let j=1;j<n;j++){
      if(A[0][j]===0) dp[0][j]=dp[0][j-1];
    }

    for(let i=1;i<m;i++) {
      for(let j=1;j<n;j++) {
        if(A[i][j]===0) {
          dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
      }
    }
    return dp[m-1][n-1];
  }
};

// ✅ Test case (runs only if file is run directly)
if (require.main === module) {
  const testGrid = [
    [0, 0, 0],
    [0, 1, 0],
    [0, 0, 0]
  ];
  const result = module.exports.uniquePathsWithObstacles(testGrid);
  console.log("Output:", result);  // Should print: Output: 2
}
