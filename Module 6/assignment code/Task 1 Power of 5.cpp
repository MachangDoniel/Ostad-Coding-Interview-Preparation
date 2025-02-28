// problem link: https://leetcode.com/problems/power-of-four/description/?envType=problem-list-v2&envId=recursion
// note: slightly modified
// Modified to check if 'n' is a power of 5 instead of 4
// -2^31 <= n <= 2^31 - 1
// -4^15 <= n <= 4^15 - 1
// -5^13 <= n <= 5^13 - 1


class Solution {
    public:
        // Recursive function to check if n is a power of 5
        bool check(int n, int power) {
            // Base case: if n is exactly 5^power, return true
            if (n == pow(5, power)) return true;

            // If we exceed the maximum power limit, return false
            if (power == 13) return false;

            // Recursive call to check for the next power of 5
            return check(n, power + 1);
        }

        // Function to determine if a number is a power of 5
        bool isPowerOfFour(int n) {
            return check(n, -13); // Start checking from 5^(-13) up to 5^13
        }
    };
