#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;
    
    int len = S.length();
    bool isPalindrome = true;
    
    // Check palindrome by comparing characters from both ends
    for (int i = 0; i < len / 2; i++) {
        if (S[i] != S[len - i - 1]) {
            isPalindrome = false;
            break;
        }
    }
    
    // Output result
    cout << (isPalindrome ? "YES" : "NO") << endl;

    return 0;
}
