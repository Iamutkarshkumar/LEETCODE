//APPROACH 1: RECURSION + MEMO
// class Solution {
// public:
//     int dp[1001][1001];
//     bool isPredecessor(string& a,string & b){
//         int n=a.length(),m=b.length();
//         int i=0,j=0;
//         if(abs(m-n)!=1) return false;
//         while(i<n and j<m){
//             if(a[i]==b[j]){
//                 i++;
//                 j++;
//             }
//             else j++;
//         }
//         return (i==n);
//     }
//     int solve(int idx,int prev,vector<string>& words){
//         if(idx>=words.size()) return 0;
//         if(prev!=-1 and dp[idx][prev]!=-1) return dp[idx][prev];
//         int take=(prev==-1 or isPredecessor(words[prev],words[idx])) ? 1+solve(idx+1,idx,words) : 0;
//         int skip=solve(idx+1,prev,words);
//         if(prev!=-1) dp[idx][prev]=max(take,skip);
//         return max(take,skip);
//     }
//     static bool cmp(string &a,string& b){
//         return a.length()<b.length();
//     }
//     int longestStrChain(vector<string>& words) {
//         sort(begin(words),end(words),cmp);
//         memset(dp,-1,sizeof(dp));
//         return solve(0,-1,words);
//     }
// };

//APPROACH 2: BOTTOM UP
class Solution {
public:
    bool isPredecessor(string& a,string & b){
        int n=a.length(),m=b.length();
        int i=0,j=0;
        if(abs(m-n)!=1) return false;
        while(i<n and j<m){
            if(a[i]==b[j]){
                i++;
                j++;
            }
            else j++;
        }
        return (i==n);
    }
    static bool cmp(string &a,string& b){
        return a.length()<b.length();
    }
    int longestStrChain(vector<string>& words) {
        sort(begin(words),end(words),cmp);
        int n=words.size();
        int ans=1;
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(isPredecessor(words[j],words[i])){
                    dp[i]=max(dp[i],1+dp[j]);
                    ans=max(ans,dp[i]);
                }
            }
        }
        return ans;
    }
};