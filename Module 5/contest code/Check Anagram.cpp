#include <iostream>
#include <string>
#include <vector>
using namespace std;

string are_anagrams(const string &a, const string &b) {
    if (a.size() != b.size()) return "NO";
    vector<int> freq(26, 0);

    for (char c : a) {
        freq[c - 'a']++;
    }

    for (char c : b) {
        freq[c - 'a']--;
    }

    for (int count : freq) {
        if (count != 0) {
            return "NO";
        }
    }

    return "YES";
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << are_anagrams(a, b) << endl;
    return 0;
}
