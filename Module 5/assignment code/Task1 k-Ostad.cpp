#include<bits/stdc++.h>
using namespace std;

void k_Ostad(string s1,string s2,int k){
    // Frequency maps for both strings
    map<char,int> mp1,mp2;
    
    // Count character frequencies for s1
    for(int i=0;i<s1.size();i++){
        mp1[s1[i]]++;
    }
    // Count character frequencies for s2
    for(int i=0;i<s2.size();i++){
        mp2[s2[i]]++;
    }
    // Count excess characters in both strings
    int s1HasS2DoesntHave=0,s2HasS1DoesntHave=0;
    for(char ch='a';ch<='z';ch++){
        if(mp1[ch]>mp2[ch]) s1HasS2DoesntHave+=mp1[ch]-mp2[ch];
        if(mp2[ch]>mp1[ch]) s2HasS1DoesntHave+=mp2[ch]-mp1[ch];
    }
    // Minimum operations needed to make both strings equal
    int need=max(s1HasS2DoesntHave,s2HasS1DoesntHave);

    // 1. min(s1HasS2DoesntHave,s2HasS1DoesntHave) times swap
    // 2. max(s1HasS2DoesntHave,s2HasS1DoesntHave)-min(s1HasS2DoesntHave,s2HasS1DoesntHave) times insert/delete

     // If the needed operations are within k, it's possible
    if(need<=k) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

int main(){
    // string s1,s2; cin>>s1>>s2;
    // int k; cin>>k; 
    // k_Ostad(s1,s2,k);
    k_Ostad("ostad", "boss", 1);        // No
    k_Ostad("anagram", "grammar", 2);   // Yes
    k_Ostad("aabcz", "abcdeyy", 3);     // No
    k_Ostad("aabcz", "abcdeyy", 4);     // Yes
    return 0;
}