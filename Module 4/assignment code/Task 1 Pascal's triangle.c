#include <stdio.h>

// Function to generate and print Pascal's Triangle up to the specified number of rows
void generatePascalsTriangle(int numRows) {
    // Declare a 2D array to store the triangle values
    int triangle[numRows][numRows];
    
    // Loop through each row
    for (int row = 0; row < numRows; row++) {
        // Loop through each column in the current row
        for (int col = 0; col <= row; col++) {
            // The first and last elements in each row are 1
            if (col == 0 || col == row) {
                triangle[row][col] = 1;
            } else {
                // Other elements are the sum of the two elements above them
                triangle[row][col] = triangle[row - 1][col - 1] + triangle[row - 1][col];
            }
            
            // Print the value at the current position
            printf("%d ", triangle[row][col]);
        }
        // Print a newline after each row
        printf("\n");
    }
}

int main() {
    int numRows;

    // Prompt the user to input the number of rows for Pascal's Triangle
    printf("Enter number of rows: ");
    scanf("%d", &numRows);

    // Generate and print the triangle
    generatePascalsTriangle(numRows);

    return 0;
}
