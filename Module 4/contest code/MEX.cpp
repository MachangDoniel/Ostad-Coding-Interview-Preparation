#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int N;
    cin >> N;

    set<int> numSet;
    int num;

    // Read input numbers and insert into a set
    for (int i = 0; i < N; i++) {
        cin >> num;
        numSet.insert(num);
    }

    // Find the smallest missing integer
    int missing = 0;
    while (numSet.count(missing)) {
        missing++;
    }

    cout << missing << endl;
    return 0;
}
