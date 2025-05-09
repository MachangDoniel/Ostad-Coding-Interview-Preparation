#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool backtrack(int n, vector<int>& result, unordered_set<int>& visited, int total) {
    if (result.size() == total) {
        return true;  // Found full Gray code sequence
    }

    int current = result.back();

    for (int i = 0; i < n; i++) {
        int next = current ^ (1 << i);  // Flip the i-th bit

        if (visited.find(next) == visited.end()) {
            visited.insert(next);
            result.push_back(next);

            if (backtrack(n, result, visited, total)) {
                return true;  // Valid sequence found
            }

            // Backtrack
            visited.erase(next);
            result.pop_back();
        }
    }

    return false;  // No valid sequence found from current state
}

void generateGrayCode(int n, vector<int>& result) {
    unordered_set<int> visited;
    int total = 1 << n;

    result.push_back(0);
    visited.insert(0);

    backtrack(n, result, visited, total);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> result;
        generateGrayCode(n, result);

        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
