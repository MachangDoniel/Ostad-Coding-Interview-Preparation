import java.util.Scanner;

public class PascalsTriangle {

    // Function to generate and print Pascal's Triangle up to the specified number of rows
    public static void generatePascalsTriangle(int numRows) {
        // Declare a 2D array to store the triangle values
        int[][] triangle = new int[numRows][numRows];
        
        // Iterate through each row
        for (int row = 0; row < numRows; row++) {
            // Iterate through each column in the current row
            for (int col = 0; col <= row; col++) {
                // First and last elements of each row are always 1
                if (col == 0 || col == row) {
                    triangle[row][col] = 1;
                } else {
                    // Other elements are the sum of the two numbers above them
                    triangle[row][col] = triangle[row - 1][col - 1] + triangle[row - 1][col];
                }
                
                // Print the value at the current position
                System.out.print(triangle[row][col] + " ");
            }
            // Print a newline after each row is printed
            System.out.println();
        }
    }

    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Prompt the user to input the number of rows for Pascal's Triangle
        System.out.print("Enter number of rows: ");
        int numRows = scanner.nextInt();

        // Generate and print the triangle
        generatePascalsTriangle(numRows);
    }
}
