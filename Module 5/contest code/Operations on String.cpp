// **Operations on String**

// ---

// **Problem Statement**
// You are given a string $S$ consisting of lowercase English letters. You have to perform two types of operations on this string several times.

// * **Operation 1:** Reverse the string $S$.
// * **Operation 2:** Given an integer $X$ and a lowercase English letter $C$:

//   * If $X = 1$, add $C$ to the **beginning** of the string $S$.
//   * If $X = 2$, add $C$ to the **end** of the string $S$.

// Since $S$ can be very large and the number of operations is large, performing these operations one by one naively will be slow. You only need the **final string** after performing all the operations sequentially.

// ---

// **Input**

// * First line: A nonempty string $S$.
// * Second line: An integer $Q$, the number of operations.
// * Next $Q$ lines: Each line describes an operation.

//   * If $T_i = 1$, it is operation type 1 (reverse).
//   * If $T_i = 2$, then the line also contains two more values: an integer $X_i$ and a character $C_i$.

// ---

// **Output**
// Print the final resulting string after all operations.

// ---

// **Constraints**

// * $1 \leq |S| \leq 10^5$
// * $1 \leq Q \leq 2 \times 10^5$
// * $T_i \in \{1, 2\}$
// * $X_i \in \{1, 2\}$ (if provided)
// * $C_i$ is a lowercase English letter.

// ---

// **Example 1:**

// ```
// Input:
// a
// 4
// 2 1 p
// 1
// 2 2 c
// 1

// Output:
// cpa
// ```

// ---

// **Example 2:**

// ```
// Input:
// a
// 6
// 2 2 a
// 2 1 b
// 1
// 2 2 c
// 1
// 1

// Output:
// aabc
// ```

// ---

// **Explanation for Example 1:**

// * Start: $S = "a"$
// * Operation 1 (2 1 p): Add 'p' at beginning → $S = "pa"$
// * Operation 2 (1): Reverse → $S = "ap"$
// * Operation 3 (2 2 c): Add 'c' at end → $S = "apc"$
// * Operation 4 (1): Reverse → $S = "cpa"$

// Final string: `"cpa"`



#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    int q;
    cin >> q;




    deque<char> dq(s.begin(), s.end());  // Initialize deque with the original string
    bool is_reversed = false;  // Track if the string is currently reversed

    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;

        if (t == 1) {
            // Reverse operation: flip the state
            is_reversed = !is_reversed;
        } else {
            // Add operation
            int x;
            char c;
            cin >> x >> c;

            if (is_reversed) {
                // Reverse the position of insertion
                if (x == 1) {
                    // If the string is reversed, adding to the "beginning" means adding to the back
                    dq.push_back(c);
                } else {
                    // Adding to the "end" means adding to the front
                    dq.push_front(c);
                }
            } else {
                // Normal case (not reversed)
                if (x == 1) {
                    // Add to the front
                    dq.push_front(c);
                } else {
                    // Add to the back
                    dq.push_back(c);
                }
            }
        }
    }

    // If the string is reversed, we need to reverse the deque
    if (is_reversed) {
        reverse(dq.begin(), dq.end());
    }

    // Output the final string
    for (char c : dq) {
        cout << c;
    }
    cout << endl;

    return 0;
}
