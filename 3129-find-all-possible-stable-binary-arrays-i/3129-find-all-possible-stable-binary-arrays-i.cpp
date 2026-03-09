class Solution {
public:
    int dp[205][205][2];
    int M=1e9+7;
    int solve(int oneLeft,int zeroLeft,bool lastWasOne,int limit){
        if(oneLeft==0 and zeroLeft==0) return 1;
        if(dp[oneLeft][zeroLeft][lastWasOne]!=-1) return dp[oneLeft][zeroLeft][lastWasOne];
        int ans=0;
        if(lastWasOne==true){
            for(int len=1;len<=min(zeroLeft,limit);len++){
                ans=(ans+solve(oneLeft,zeroLeft-len,false,limit))%M;
            }
        }
        else{
            for(int len=1;len<=min(oneLeft,limit);len++){
                ans=(ans+solve(oneLeft-len,zeroLeft,true,limit))%M;
            }
        }
        return dp[oneLeft][zeroLeft][lastWasOne]=ans;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp,-1,sizeof(dp));
        int startWithOne=solve(one,zero,false,limit);
        int startWithZero=solve(one,zero,true,limit);
        return (startWithOne+startWithZero)%M;
    }
};