#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    unordered_set<int> seen;
    int num;
    
    for (int i = 0; i < N; i++) {
        cin >> num;
        // If num is already in the set, it's the duplicate
        if (seen.find(num) != seen.end()) {
            cout << num << endl;
            return 0; // We found the duplicate, no need to continue
        }
        // Otherwise, add it to the set
        seen.insert(num);
    }
    
    return 0;
}
