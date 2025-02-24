// problem link: https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/description/?envType=problem-list-v2&envId=recursion


class Solution {
    public:
        char find(int k,string str){
            if(str.size()>k){
                return str[k-1];
            }
            string add;
            for(int i=0;i<str.size();i++){
                add+=('a'+(str[i]-'a'+1)%26);
            }
            return find(k,str+add);
        }
        char kthCharacter(int k) {
            return find(k,"a");
        }
    };