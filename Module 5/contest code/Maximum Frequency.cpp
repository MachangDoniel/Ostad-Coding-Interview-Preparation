#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string S;
    cin >> S;

    vector<int> freq(26, 0); // Frequency array for 'a' to 'z'

    // Count occurrences of each character
    for (char c : S) {
        freq[c - 'a']++;
    }

    char maxChar = 'z'; // Default to highest possible character
    int maxCount = 0;

    // Find character with maximum frequency (smallest if tie)
    for (int i = 0; i < 26; i++) {
        if (freq[i] > maxCount) {
            maxCount = freq[i];
            maxChar = 'a' + i;
        }
    }

    // Output the result
    cout << maxChar << " " << maxCount << endl;

    return 0;
}
