#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int N, S;
    cin >> N >> S;

    int num;
    unordered_set<int> seen;

    for (int i = 0; i < N; i++) {
        cin >> num;

        // Check if the complement exists in the set
        if (seen.find(S - num) != seen.end()) {
            cout << "Yes" << endl;
            return 0;
        }

        // Add the current number to the set
        seen.insert(num);
    }

    // If no pair is found
    cout << "No" << endl;
    return 0;
}
