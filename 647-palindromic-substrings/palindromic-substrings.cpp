class Solution {
public:
    unordered_map<string,int> dp;
    bool checkPalindrome(int i, int j,string& s){
        int len=j-i+1;
        string x = s.substr(i,len);
        if(dp.count(x)) return dp[x];
        for(int i=0;i<len/2;i++) if(x[i]!=x[len-i-1]) return dp[x]=false;
        return dp[x]=true;
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