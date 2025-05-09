#include <bits/stdc++.h>
using namespace std;

// Backtracking function to count valid partitions
int countValidSentencesBacktracking(const string &str, int index, unordered_set<string> &dict) {
    // If we have reached the end of the string, it's a valid sentence
    if (index == str.length()) {
        return 1;
    }
    
    int count = 0;
    
    // Try every possible substring starting from the current index
    for (int i = index + 1; i <= str.length(); ++i) {
        string word = str.substr(index, i - index);
        
        // If the current substring is in the dictionary, recurse on the remaining part of the string
        if (dict.find(word) != dict.end()) {
            count += countValidSentencesBacktracking(str, i, dict);
        }
    }
    
    return count;
}

int main() {
    int N;
    cin >> N;
    
    unordered_set<string> dict;
    for (int i = 0; i < N; ++i) {
        string word;
        cin >> word;
        dict.insert(word);
    }

    int M;
    cin >> M;
    
    for (int i = 0; i < M; ++i) {
        string s;
        cin >> s;
        cout << countValidSentencesBacktracking(s, 0, dict) << endl;
    }
    
    return 0;
}