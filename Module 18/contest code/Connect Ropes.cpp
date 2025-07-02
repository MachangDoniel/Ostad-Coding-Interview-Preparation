// Connect Ropes

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    priority_queue<long long, vector<long long>, greater<long long>> minHeap;

    for (int i = 0; i < N; ++i) {
        long long length;
        cin >> length;
        minHeap.push(length);
    }

    long long totalCost = 0;

    while (minHeap.size() > 1) {
        long long first = minHeap.top(); minHeap.pop();
        long long second = minHeap.top(); minHeap.pop();

        long long newRope = first + second;
        totalCost += newRope;
        minHeap.push(newRope);
    }

    cout << totalCost << endl;
    return 0;
}