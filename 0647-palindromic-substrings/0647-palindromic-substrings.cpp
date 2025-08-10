class Solution {
public:
    unordered_map<string,bool> dp;
    bool checkPalindrome(int l, int r, string& s){
        string x = s.substr(l, r - l + 1);
        if(dp.count(x)) return dp[x];
        int len = x.length();
        for(int k=0; k < len/2; k++)
            if(x[k] != x[len-k-1])
                return dp[x] = false;
        return dp[x] = true;
    }
    int countSubstrings(string s) {
        int n = s.length(), ans = 0;
        for(int i=0; i<n; i++)
            for(int j=i; j<n; j++)
                ans += checkPalindrome(i, j, s);
        return ans;
    }
};
