#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


string shortest_palindrome(string s) {
    int n = s.size();
    string reversed_s = s;
    reverse(reversed_s.begin(), reversed_s.end());

    for (int i = 0; i < n; ++i) {
        if (s.substr(0, n - i) == reversed_s.substr(i)) {
            return reversed_s.substr(0, i) + s;
        }
    }

    return reversed_s + s;
}

int main() {
    string s;
    cin >> s;
    cout << shortest_palindrome(s) << endl;
    return 0;
}
