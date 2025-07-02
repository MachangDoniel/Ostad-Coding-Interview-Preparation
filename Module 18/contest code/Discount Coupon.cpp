// Discount Coupon

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    priority_queue<long long> pq;
    for (int i = 0; i < N; ++i) {
        long long price;
        cin >> price;
        pq.push(price);
    }

    while (M-- && !pq.empty()) {
        long long top = pq.top(); pq.pop();
        top = top / 2;
        pq.push(top);
    }

    long long totalCost = 0;
    while (!pq.empty()) {
        totalCost += pq.top();
        pq.pop();
    }

    cout << totalCost << endl;
    return 0;
}