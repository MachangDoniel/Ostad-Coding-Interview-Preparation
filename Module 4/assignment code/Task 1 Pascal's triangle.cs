using System;

class PascalsTriangle
{
    // Function to generate and print Pascal's Triangle up to the specified number of rows
    static void GeneratePascalsTriangle(int numRows)
    {
        // Declare a 2D array to store the triangle values
        int[,] triangle = new int[numRows, numRows];
        
        // Loop through each row
        for (int row = 0; row < numRows; row++)
        {
            // Loop through each column in the current row
            for (int col = 0; col <= row; col++)
            {
                // The first and last elements in each row are 1
                if (col == 0 || col == row)
                {
                    triangle[row, col] = 1;
                }
                else
                {
                    // Other elements are the sum of the two elements above them
                    triangle[row, col] = triangle[row - 1, col - 1] + triangle[row - 1, col];
                }
                
                // Print the value at the current position
                Console.Write(triangle[row, col] + " ");
            }
            // Print a newline after each row
            Console.WriteLine();
        }
    }

    static void Main()
    {
        // Prompt the user to input the number of rows for Pascal's Triangle
        Console.Write("Enter number of rows: ");
        int numRows = int.Parse(Console.ReadLine());

        // Generate and print the triangle
        GeneratePascalsTriangle(numRows);
    }
}
