// **String Reverse**

// ---

// **Problem Statement**
// You are given a string $S$. Your task is to reverse the string. Reversing a string means rearranging the characters so that the last character becomes the first, the second last becomes the second, and so forth.

// ---

// **Input**
// One line containing the string $S$, consisting only of lowercase English letters.

// ---

// **Output**
// Print the reversed string.

// ---

// **Constraints**

// * $1 \leq |S| \leq 50000$
// * $S$ contains only lowercase English letters $(a-z)$.

// ---

// **Example 1:**
// Input:

// ```
// apple
// ```

// Output:

// ```
// elppa
// ```

// ---

// **Example 2:**
// Input:

// ```
// ostad
// ```

// Output:

// ```
// datso
// ```

// ---

// **Explanation:**
// Reverse the order of characters in the string and print the result.



#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string S;
    cin >> S;
    
    // Reverse the string using built-in function
    reverse(S.begin(), S.end());
    
    // Output the reversed string
    cout << S << endl;

    return 0;
}
