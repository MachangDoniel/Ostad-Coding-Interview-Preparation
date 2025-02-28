// Problem link: https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/description/?envType=problem-list-v2&envId=recursion

class Solution {
    public:
        // Recursive function to generate the string and find the k-th character
        char find(int k, string str) {
            // If the string has grown large enough to contain k-th character, return it
            if (str.size() > k) {
                return str[k - 1];
            }

            string add; // String to store the transformed version of str
            for (int i = 0; i < str.size(); i++) {
                // Generate the next sequence by shifting each character to the next one in the alphabet
                add += ('a' + (str[i] - 'a' + 1) % 26);
            }

            // Recursively call find with the newly formed string
            return find(k, str + add);
        }

        // Function to find the k-th character starting with "a"
        char kthCharacter(int k) {
            return find(k, "a");
        }
    };
