// problem link: https://leetcode.com/problems/power-of-four/description/?envType=problem-list-v2&envId=recursion
// note: slightly modified
// in case of 4, 
// -2^31 <= n <= 2^31 - 1
// -4^15 <= n <= 4^15 - 1
// -5^13 <= n <= 5^13 - 1

class Solution {
    public:
        bool check(int n,int power){
            if(n==pow(4,power)) return true;
            if(power==14) return false;
            return check(n,power+1);
        }
        bool isPowerOfFour(int n) {
            return check(n,-13);
            return false;
        }
    };