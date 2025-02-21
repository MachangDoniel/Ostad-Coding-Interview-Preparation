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
