// K-th Prefix Max


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> P(N);
    for (int i = 0; i < N; i++) cin >> P[i];

    priority_queue<int, vector<int>, greater<int>> minHeap; // min heap

    for (int i = 0; i < N; i++) {
        if ((int)minHeap.size() < K) {
            minHeap.push(P[i]);
        } else {
            if (P[i] > minHeap.top()) {
                minHeap.pop();
                minHeap.push(P[i]);
            }
        }

        if (i + 1 >= K) {
            cout << minHeap.top() << "\n";
        }
    }

    return 0;
}