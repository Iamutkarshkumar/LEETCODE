class Solution {
public:
    int dp[1001][1001];
    bool isPalindrome(int i,int j,string& s){
        if(i >= j) return dp[i][j] = true;        
        if(dp[i][j] != -1) return dp[i][j];       
        if(s[i] != s[j]) return dp[i][j] = false; 
        return dp[i][j] = isPalindrome(i+1, j-1, s); 
    }
    string longestPalindrome(string s) {
        memset(dp,-1,sizeof(dp));
        int n=s.length();
        priority_queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(i,j,s)) q.push({j-i+1 , {i,j}});
            }
        }
        auto x=q.top();
        return s.substr(x.second.first,x.first);
    }
};