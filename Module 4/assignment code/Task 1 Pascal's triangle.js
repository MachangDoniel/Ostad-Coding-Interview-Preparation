function generatePascalsTriangle(numRows) {
    // Create a 2D array to store the triangle values
    let triangle = Array.from({ length: numRows }, () => Array(numRows).fill(0));

    // Loop through each row
    for (let row = 0; row < numRows; row++) {
        // Loop through each column in the current row
        for (let col = 0; col <= row; col++) {
            // The first and last elements in each row are 1
            if (col === 0 || col === row) {
                triangle[row][col] = 1;
            } else {
                // Other elements are the sum of the two elements above them
                triangle[row][col] = triangle[row - 1][col - 1] + triangle[row - 1][col];
            }
            
            // Print the value at the current position
            process.stdout.write(triangle[row][col] + " ");
        }
        // Print a newline after each row
        console.log();
    }
}

// Input number of rows from the user
let numRows = parseInt(prompt("Enter number of rows: "), 10);

// Generate and print Pascal's Triangle
generatePascalsTriangle(numRows);
