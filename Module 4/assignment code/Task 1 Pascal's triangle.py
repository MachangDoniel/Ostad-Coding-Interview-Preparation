def generate_pascals_triangle(num_rows):
    # Initialize a 2D list to store the values of the triangle
    triangle = [[0] * num_rows for _ in range(num_rows)]
    
    # Loop through each row
    for row in range(num_rows):
        # Loop through each column in the current row
        for col in range(row + 1):
            # The first and last elements in each row are 1
            if col == 0 or col == row:
                triangle[row][col] = 1
            else:
                # Other elements are the sum of the two elements above them
                triangle[row][col] = triangle[row - 1][col - 1] + triangle[row - 1][col]
            
            # Print the value at the current position
            print(triangle[row][col], end=" ")
        # Print a newline after each row
        print()

# Input number of rows from the user
num_rows = int(input("Enter number of rows: "))

# Generate and print Pascal's Triangle
generate_pascals_triangle(num_rows)
