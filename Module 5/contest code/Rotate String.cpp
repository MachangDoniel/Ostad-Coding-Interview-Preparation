// **Rotate String**

// ---

// **Problem Statement:**
// You are given a string $S$ of length 5. You need to move the first character of $S$ to the end of the string and then print the resulting string.

// ---

// **Input:**
// One line containing a string $S$ of length 5, consisting of lowercase English letters.

// ---

// **Output:**
// Print the resulting string after moving the first character of $S$ to the end.

// ---

// **Constraints:**

// * $|S| = 5$
// * $S$ contains only lowercase English letters $a-z$.

// ---

// **Example 1:**
// Input:

// ```
// sworn
// ```

// Output:

// ```
// worns
// ```

// ---

// **Example 2:**
// Input:

// ```
// yhapp
// ```

// Output:

// ```
// happy
// ```

// ---

// If you'd like, I can also provide a sample code solution for this!


#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;

    // Move the first character to the end
    string result = S.substr(1) + S[0];

    // Output the modified string
    cout << result << endl;

    return 0;
}
