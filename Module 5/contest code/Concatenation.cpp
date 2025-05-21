// **Concatenation**

// ---

// **Problem Statement**
// You are given two strings $A$ and $B$. Your task is to concatenate $B$ followed by $A$ and print the resulting string.

// ---

// **Input**
// Two strings $A$ and $B$.

// ---

// **Output**
// Print the concatenation of $B + A$.

// ---

// **Constraints**

// * $1 \leq |A|, |B| \leq 100$
// * Strings $A$ and $B$ contain only lowercase English letters $(a-z)$.

// ---

// **Example 1:**
// Input:

// ```
// tad os
// ```

// Output:

// ```
// ostad
// ```

// ---

// **Example 2:**
// Input:

// ```
// fast break
// ```

// Output:

// ```
// breakfast
// ```

// ---

// **Explanation:**
// Simply join the second string $B$ first, then append the first string $A$.


#include <iostream>
#include <string>
using namespace std;

int main() {
    string A, B;
    cin >> A >> B;
    
    // Concatenate B and A
    string result = B + A;
    
    // Output the result
    cout << result << endl;

    return 0;
}
