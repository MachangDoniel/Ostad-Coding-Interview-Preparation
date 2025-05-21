// **Move Up**

// ---

// **Problem Statement:**
// You are given a string $S$ containing both uppercase and lowercase English letters. Your task is to convert **all letters** in $S$ to uppercase.

// ---

// **Input:**
// One line containing a string $S$ with only uppercase and lowercase English letters.

// ---

// **Output:**
// Print the string $S$ after converting all letters to uppercase.

// ---

// **Constraints:**

// * $1 \leq |S| \leq 5000$
// * $S$ contains only uppercase $(A-Z)$ or lowercase $(a-z)$ letters.

// ---

// **Example 1:**
// Input:

// ```
// HoUse
// ```

// Output:

// ```
// HOUSE
// ```

// ---

// **Example 2:**
// Input:

// ```
// CodEr
// ```

// Output:

// ```
// CODER
// ```

// ---

// If you want, I can provide you with a simple code snippet to solve this. Would you like that?


#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;

    // Convert each character to uppercase
    for (char &c : S) {
        c = toupper(c);
    }

    // Output the modified string
    cout << S << endl;

    return 0;
}
