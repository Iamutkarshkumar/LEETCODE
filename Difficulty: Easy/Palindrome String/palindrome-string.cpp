class Solution {
  public:
    bool isPalindrome(string& s) {
        int n=s.length();
        for(int i=0;i*2<n;i++){
            if(s[i]!=s[n-1-i]) return false;
        }
        return true;
    }
};