// Sort Queries

#include <iostream>
#include <deque>
#include <queue>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    deque<long long> dq;
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            long long x;
            cin >> x;
            dq.push_back(x);
        }
        else if (type == 2) {
            if (!pq.empty()) {
                cout << pq.top() << '\n';
                pq.pop();
            } else {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        }
        else if (type == 3) {
            while (!dq.empty()) {
                pq.push(dq.front());
                dq.pop_front();
            }
        }
    }

    return 0;
}