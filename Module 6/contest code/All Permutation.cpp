// **All Permutation**

// **Problem Statement**
// You are given a string **S** of all **unique characters**. Your task is to print **all permutations** of the string (i.e., all possible arrangements of the characters) in **lexicographically increasing order**.

// ---

// **Input**
// A single line containing a string **S** of unique lowercase English letters.

// **Output**
// Print all permutations of **S**, one per line, in **lexicographically increasing order**.

// ---

// **Constraints**

// * 1 ≤ |S| ≤ 8
// * **S** contains only lowercase English letters and all characters are **unique**.

// ---

// **Example 1**
// **Input:**

// ```
// bac
// ```

// **Output:**

// ```
// abc
// acb
// bac
// bca
// cab
// cba
// ```

// **Example 2**
// **Input:**

// ```
// sob
// ```

// **Output:**

// ```
// bos
// bso
// obs
// osb
// sbo
// sob
// ```



#include <bits/stdc++.h>
using namespace std;

string s;
vector<string>res;

void call(string mask){
    if(mask.size()==s.size()){
        for(int i=0;i<s.size();i++){
            cout<<s[mask[i]-'0'];
        }
        cout<<endl;
        return;
    }   
    for(int i=0;i<s.size();i++){
        bool found=false;
        for(int j=0;j<mask.size();j++){
            if(i==(mask[j]-'0')) found=true;
        }
        if(!found){
            call(mask+char('0'+i));
        }
    }
}


int main() {
    cin>>s;
    sort(s.begin(),s.end());
    call("");
    for(string ss:res){
        cout<<ss<<endl;
    }
    return 0;
}