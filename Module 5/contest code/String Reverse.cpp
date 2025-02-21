#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string S;
    cin >> S;
    
    // Reverse the string using built-in function
    reverse(S.begin(), S.end());
    
    // Output the reversed string
    cout << S << endl;

    return 0;
}
