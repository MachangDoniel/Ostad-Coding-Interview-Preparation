// **Maximum Frequency**

// ---

// **Problem Statement:**
// You are given a string $S$. Your task is to find the character that occurs the maximum number of times in the string, and print that character along with its number of occurrences. If there are multiple characters with the same maximum frequency, print the lexicographically smallest one.

// ---

// **Input:**
// One line containing the string $S$ consisting only of lowercase English letters.

// ---

// **Output:**
// Print two values separated by space:

// * The character with the maximum frequency
// * The number of times it occurs

// ---

// **Constraints:**

// * $1 \leq |S| \leq 50000$
// * $S$ contains only lowercase English letters $a-z$.

// ---

// **Example 1:**
// Input:

// ```
// abcbcba
// ```

// Output:

// ```
// b 3
// ```

// ---

// **Example 2:**
// Input:

// ```
// babcdcd
// ```

// Output:

// ```
// b 2
// ```

// ---

// **Explanation:**

// * In the first example:

//   * 'a' occurs 2 times
//   * 'b' occurs 3 times
//   * 'c' occurs 2 times
//     So 'b' is the max occurring character.

// * In the second example:

//   * 'b', 'c', and 'd' each occur 2 times
//     The smallest character among these is 'b', so print `b 2`.

// ---

// If you want, I can provide a sample code solution too!


#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string S;
    cin >> S;

    vector<int> freq(26, 0); // Frequency array for 'a' to 'z'

    // Count occurrences of each character
    for (char c : S) {
        freq[c - 'a']++;
    }

    char maxChar = 'z'; // Default to highest possible character
    int maxCount = 0;

    // Find character with maximum frequency (smallest if tie)
    for (int i = 0; i < 26; i++) {
        if (freq[i] > maxCount) {
            maxCount = freq[i];
            maxChar = 'a' + i;
        }
    }

    // Output the result
    cout << maxChar << " " << maxCount << endl;

    return 0;
}
