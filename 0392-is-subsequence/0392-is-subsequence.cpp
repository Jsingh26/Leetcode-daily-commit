class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx = 0;
        for(char a : t){
            if(s[idx] == a){
                idx ++;
            }
        }
        
        return idx == s.size();
    }
};