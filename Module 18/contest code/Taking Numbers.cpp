// Taking Numbers

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    priority_queue<long long> pq;
    for (int i = 0; i < N; ++i) {
        long long num;
        cin >> num;
        pq.push(num);
    }

    long long total = 0;

    for (int i = 0; i < M; ++i) {
        long long top = pq.top();
        pq.pop();
        total += top;
        pq.push(top / 2);  // floor division
    }

    cout << total << endl;
    return 0;
}