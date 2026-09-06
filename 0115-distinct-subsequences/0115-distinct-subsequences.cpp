class Solution {
public:
    int n,m;
    unordered_map<string,int> dp;
    int solve(int i,int j,string& s,string& t){
        //base case
        if(j==m) return 1;
        if(i==n) return 0;
        //memoization 
        string key = to_string(i) + "_" + to_string(j);
        if(dp.count(key)) return dp[key];

        int skip=solve(i+1,j,s,t);
        int take=0;
        if(s[i]==t[j]) take=solve(i+1,j+1,s,t);

        return dp[key]=take+skip;
    }
    int numDistinct(string s, string t) {
        n=s.length();
        m=t.length();
        return solve(0,0,s,t);
    }
};