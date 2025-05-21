// **Funny String**

// **Problem Statement**
// We call a string **funny** if its odd-positioned characters (1st, 3rd, 5th, ...) are all lowercase English letters and its even-positioned characters (2nd, 4th, 6th, ...) are all uppercase English letters.
// You are given a string $S$. You have to find out if $S$ is funny or not.

// ---

// **Input**
// A single line containing the string $S$.

// ---

// **Output**
// Print `"Yes"` if $S$ is funny, otherwise print `"No"`.

// ---

// **Constraints**

// * $1 \leq |S| \leq 1000$
// * $S$ contains uppercase (`A`–`Z`) and lowercase (`a`–`z`) English letters.

// ---

// **Example 1**

// ```
// Input  
// fUnNy  

// Output  
// Yes  
// ```

// **Example 2**

// ```
// Input  
// sAD  

// Output  
// No  
// ```

// ---

// **Notes**
// In example 2, the 3rd position character is uppercase 'D', but it should be lowercase for a funny string. Hence, the answer is `"No"`.


#include <iostream>
#include <string>
using namespace std;

string is_funny(const string &s) {
    for (int i = 0; i < s.size(); ++i) {
        if (i % 2 == 0) {
            if (!(s[i] >= 'a' && s[i] <= 'z')) {
                return "No";
            }
        }
        else {
            if (!(s[i] >= 'A' && s[i] <= 'Z')) {
                return "No";
            }
        }
    }
    return "Yes";
}

int main() {
    string s;
    cin >> s;
    cout << is_funny(s) << endl;
    return 0;
}
