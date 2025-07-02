// Running Median

#include <bits/stdc++.h>
using namespace std;

multiset<int> low, high;

void rebalance() {
    // Ensure low has the median (i.e., low.size() >= high.size())
    while (low.size() > high.size() + 1) {
        high.insert(*prev(low.end()));
        low.erase(prev(low.end()));
    }
    while (low.size() < high.size()) {
        low.insert(*high.begin());
        high.erase(high.begin());
    }
}

void insert(int x) {
    if (low.empty() || x <= *prev(low.end())) {
        low.insert(x);
    } else {
        high.insert(x);
    }
    rebalance();
}

void remove(int x) {
    if (low.find(x) != low.end()) {
        low.erase(low.find(x));
    } else {
        high.erase(high.find(x));
    }
    rebalance();
}

int get_median() {
    return *prev(low.end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    // Initialize first window
    for (int i = 0; i < k; i++) insert(a[i]);
    cout << get_median();

    // Slide window
    for (int i = k; i < n; i++) {
        remove(a[i - k]);
        insert(a[i]);
        cout << " " << get_median();
    }
    cout << "\n";
    return 0;
}