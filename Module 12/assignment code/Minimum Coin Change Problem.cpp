// Greedy

// This is the classic Coin Change problem, and greedy works ONLY for canonical coin systems (like US coins: 1, 5, 10, 25...). It fails for some tricky sets (e.g., coins 1, 3, 4 and amount 6).


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    int amount;
    cin >> amount;

    sort(coins.rbegin(), coins.rend()); // Sort descending

    int count = 0;
    for (int c : coins) {
        while (amount >= c) {
            amount -= c;
            count++;
        }
    }

    if (amount != 0)
        cout << -1 << endl; // If it's impossible to make the amount
    else
        cout << count << endl;

    return 0;
}
