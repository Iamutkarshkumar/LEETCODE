class Solution {
public:
    int dp[1001][1001];
    bool ispredecessor (string a ,string b){
        int n=a.length();
        int m=b.length();
        if(abs(m-n)!=1) return false;
        int i=0,j=0;
        while(i<n and j<m){
            if(a[i]==b[j]){
                i++;j++;
            }
            else j++;
        }
        return i==n;
    }
    int solve(int i,int p,vector<string>& words){
        if(i>=words.size()) return 0;
        if(p!=-1 and dp[i][p]!=-1) return dp[i][p];

        int take=0;
        if(p==-1 or ispredecessor(words[p],words[i])){
            take=1+solve(i+1,i,words);
        }
        int skip=solve(i+1,p,words);

        if(p!=-1) return dp[i][p]=max(take,skip);
        return max(take,skip);
    }
    static bool cmp(string a,string b){return a.length()<b.length();}
    int longestStrChain(vector<string>& words) {
        memset(dp,-1,sizeof(dp));
        sort(words.begin(),words.end(),cmp);
        return solve(0,-1,words);
    }
};