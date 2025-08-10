class Solution {
public:
    bool checkPalindrome(int i, int j,string& s){
        int len=j-i+1;
        string x = s.substr(i,len);
        for(int i=0;i<len/2;i++) if(x[i]!=x[len-i-1]) return false;
        return true;
    }
    int countSubstrings(string s) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                ans+=checkPalindrome(i,j,s);
            }
        }
        return ans;
    }
};