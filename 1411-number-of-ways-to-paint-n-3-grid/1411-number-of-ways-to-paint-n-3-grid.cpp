class Solution {
    int mod = 1e9 + 7;
public:
    int numOfWays(int n) {
        long long diff = 6, same = 6;

        for(int i = 1; i < n; i++) {
            long long s = (3*same + 2*diff)%mod;
            long long d = (2*same + 2*diff)%mod;

            same = s;
            diff = d; 
        }

        return (same + diff)%mod;
    }
};
// class Solution {
// public:
//     int solve(int i,int n,int prev1,int prev2,int prev3,int mod,vector<vector<vector<vector<int>>>>& dp){
//         if(i==n) return 1;
//         if(dp[i][prev1][prev2][prev3]!=-1) return dp[i][prev1][prev2][prev3];
//         int ans=0;
//         for(int c1=1;c1<=3;c1++){
//             if(c1==prev1) continue;
//             for(int c2=1;c2<=3;c2++){
//                 if(c2==c1 or c2==prev2) continue;
//                 for(int c3=1;c3<=3;c3++){
//                     if(c3==c2 or c3==prev3) continue;
//                     ans = (ans + solve(i+1,n,c1,c2,c3,mod,dp))%mod;
//                 }
//             }
//         }
//         return dp[i][prev1][prev2][prev3]=ans;
            
        
//     }
//     int numOfWays(int n) {
//         vector<vector<vector<vector<int>>>> dp(
//             n,
//             vector<vector<vector<int>>>(
//                 4,
//                 vector<vector<int>>(
//                     4,
//                     vector<int>(4, -1)
//                 )
//             )
//         );

//         int mod=1e9+7;
//         return solve(0,n,0,0,0,mod,dp);
//     }
// };