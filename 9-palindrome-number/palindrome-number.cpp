class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        string s=to_string(x);
        int n=s.length();
        for(int i=0;i*2<n;i++){
            if(s[i]!=s[n-i-1]) return false;
        }
        return true;
    }
};