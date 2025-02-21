#include <iostream>
#include <string>
using namespace std;

string is_funny(const string &s) {
    for (int i = 0; i < s.size(); ++i) {
        if (i % 2 == 0) {
            if (!(s[i] >= 'a' && s[i] <= 'z')) {
                return "No";
            }
        }
        else {
            if (!(s[i] >= 'A' && s[i] <= 'Z')) {
                return "No";
            }
        }
    }
    return "Yes";
}

int main() {
    string s;
    cin >> s;
    cout << is_funny(s) << endl;
    return 0;
}
