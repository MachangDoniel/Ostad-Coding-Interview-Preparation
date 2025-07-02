// Array Cost

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    priority_queue<int> pq;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        pq.push(a);
    }

    // Perform up to M operations
    while (M-- && pq.top() > 0) {
        int top = pq.top();
        pq.pop();
        pq.push(top - 1);
    }

    // Calculate final cost
    long long cost = 0;
    while (!pq.empty()) {
        long long val = pq.top();
        pq.pop();
        cost += val * val;
    }

    cout << cost << endl;
    return 0;
}