#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;

    // Convert each character to uppercase
    for (char &c : S) {
        c = toupper(c);
    }

    // Output the modified string
    cout << S << endl;

    return 0;
}
