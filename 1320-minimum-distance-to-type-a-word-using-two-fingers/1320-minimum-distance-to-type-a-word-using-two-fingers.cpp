class Solution {
public:
    int dp[301][27][27];

    pair<int,int> getPos(int c){
        return {c/6,c%6};
    }

    int dist(int a,int b){
        if(a==26 || b==26) return 0; // not used yet
        auto p1=getPos(a),p2=getPos(b);
        return abs(p1.first-p2.first)+abs(p1.second-p2.second);
    }

    int f(int i,int f1,int f2,string &w){
        if(i==w.size()) return 0;
        if(dp[i][f1][f2]!=-1) return dp[i][f1][f2];

        int curr=w[i]-'A';

        int use1 = dist(f1,curr) + f(i+1,curr,f2,w);
        int use2 = dist(f2,curr) + f(i+1,f1,curr,w);

        return dp[i][f1][f2]=min(use1,use2);
    }

    int minimumDistance(string word) {
        memset(dp,-1,sizeof(dp));
        return f(0,26,26,word);
    }
};