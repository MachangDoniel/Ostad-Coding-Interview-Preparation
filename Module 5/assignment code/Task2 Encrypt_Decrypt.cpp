#include <bits/stdc++.h>
using namespace std;

string encrypt(string s) {
    int n = s.size();
    string result = "";
    int i = 0;

    // Step 1: Iterate through the string to count consecutive identical characters
    while (i < n) {
        int count = 1; // At least one occurrence of the character
        char char_at_i = s[i]; // Current character

        // Step 2: Count consecutive occurrences of the same character
        while (i + 1 < n && s[i] == s[i + 1]) {
            count++;
            i++;
        }

        // Step 3: Append the character and its frequency
        result += to_string(count) + char_at_i;

        i++; // Move to the next character
    }

    // Step 4: Reverse the transformed string and return
    reverse(result.begin(), result.end());
    return result;
}

string decrypt(string encrypted) {
    int n = encrypted.size();
    string result = "";
    int i = 0;

    // Step 1: Reverse the encrypted string to get the original transformed string
    reverse(encrypted.begin(), encrypted.end());

    // Step 2: Iterate through the reversed string to extract counts and characters
    while (i < n) {
        // Extract the count
        string count_str = "";
        while (i < n && isdigit(encrypted[i])) {
            count_str += encrypted[i];
            i++;
        }

        // Convert the count to integer
        int count = stoi(count_str);

        // The next character is the one that occurred 'count' times
        result += string(count, encrypted[i]);
        i++; // Move to the next character
    }

    return result;
}

int main() {
    string input1 = "aaaaaaaaaaa";
    string input2 = "ostad";

    // Encrypt the strings
    string encrypted1 = encrypt(input1);
    string encrypted2 = encrypt(input2);

    // Print encrypted outputs
    cout << "Encrypted '" << input1 << "': " << encrypted1 << endl;
    cout << "Encrypted '" << input2 << "': " << encrypted2 << endl;

    // Decrypt the strings
    string decrypted1 = decrypt(encrypted1);
    string decrypted2 = decrypt(encrypted2);

    // Print decrypted outputs
    cout << "Decrypted '" << encrypted1 << "': " << decrypted1 << endl;
    cout << "Decrypted '" << encrypted2 << "': " << decrypted2 << endl;

    // Check if the decrypted strings match the originals
    cout << "Decryption matches original for '" << input1 << "': " << (decrypted1 == input1 ? "True" : "False") << endl;
    cout << "Decryption matches original for '" << input2 << "': " << (decrypted2 == input2 ? "True" : "False") << endl;

    return 0;
}
