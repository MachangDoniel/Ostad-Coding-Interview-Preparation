#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    set<int> setA, intersection;
    vector<int> result;

    // Read first array into a set
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        setA.insert(num);
    }

    // Read second array and check for intersection
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        if (setA.count(num)) { // If num is in setA, it's a common element
            intersection.insert(num);
        }
    }

    // Print the results
    cout << intersection.size() << endl;
    for (int num : intersection) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
