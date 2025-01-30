class Solution {
public:
    bool detectCapitalUse(string word) {
        int i='A'-'0';
        int j='Z'-'0';

        int small=0;
        int cap=0;
        for(auto ele: word) {
            if(ele-'0'>=i and ele-'0'<=j) cap++;
            else small++;
        }
        int n=word.length();
        if(cap==n or small==n) return true;
        if(cap==1 and (word[0]-'0'>=i and word[0]-'0'<=j)) return true;
        return false;
    }
};