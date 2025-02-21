#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;

    // Move the first character to the end
    string result = S.substr(1) + S[0];

    // Output the modified string
    cout << result << endl;

    return 0;
}
