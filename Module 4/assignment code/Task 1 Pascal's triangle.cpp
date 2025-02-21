#include <bits/std++.h>

using namespace std;

// Function to generate and print Pascal's Triangle up to the specified number of rows
void generatePascalsTriangle(int numRows) {
    // Declare a 2D array to store the triangle values
    int triangle[numRows][numRows];

    // Iterate through each row
    for (int row = 0; row < numRows; row++) {
        // Iterate through each column in the current row
        for (int col = 0; col <= row; col++) {
            // First and last elements of each row are always 1
            if (col == 0 || col == row) 
                triangle[row][col] = 1;
            else 
                // Other elements are the sum of the two numbers above them
                triangle[row][col] = triangle[row-1][col-1] + triangle[row-1][col]; 
            
            // Print the value at the current position
            cout << triangle[row][col] << " "; 
        }
        // Print a newline after each row is printed
        cout << endl;
    }
}

int main() {
    int numRows;

    // Prompt the user to input the number of rows for Pascal's Triangle
    cout << "Enter number of rows: ";
    cin >> numRows;

    // Call the function to generate and print the triangle
    generatePascalsTriangle(numRows);

    return 0;
}
