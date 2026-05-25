//O(n×(maxJump−minJump))
//TLE
// class Solution {
// public:
//     int n;
//     unordered_map<int,int> dp;
//     int solve(int idx,int mn,int mx,string& s){
//         if(idx>=n) return 0;
//         if(idx==n-1) return 1;
//         if(dp.count(idx)!=0) return dp[idx];
//         for(int i=idx+mn;i<=min(idx+mx,n-1);i++){
//             if(s[i]=='0'){
//                 if(solve(i,mn,mx,s))
//                     return dp[idx]=1;
//             }
//         }
//         return dp[idx]=0;
//     }
//     bool canReach(string s, int minJump, int maxJump) {
//         n=s.length();
//         int ans=solve(0,minJump,maxJump,s);
//         return ans>0;
//     }
// };
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.length();
        queue<int> q;
        vector<int> vis(n,0);
        q.push(0);
        vis[0]=1;
        int farthest=0;
        while(!q.empty()){
            int currIdx=q.front();q.pop();
            if(currIdx==n-1) return true;
            int start=max(currIdx+minJump,farthest);
            int end=min(currIdx+maxJump,n-1);
            for(int i=start;i<=end;i++){
                if(s[i]=='0' and vis[i]==0){
                    q.push(i);
                    vis[i]=1;
                }
            }
            farthest=end+1;
        }
        return false;
    }
};