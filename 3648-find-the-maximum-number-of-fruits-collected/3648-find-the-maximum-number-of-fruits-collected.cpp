class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n=fruits.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        int child1collect=0;
        for(int i=0;i<n;i++) child1collect+=fruits[i][i];

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i>j and i+j<n-1) dp[i][j]=0;
                else if(i<j and i+j<n-1) dp[i][j]=0;
                else dp[i][j]=fruits[i][j];
            }
        }
        for(int i=1;i<n;i++){
            for(int j=i+1;j<n;j++){
                dp[i][j]+=max({dp[i-1][j] , dp[i-1][j-1] , (j+1<n) ? dp[i-1][j+1] : 0});
            }
        }
        for(int j=1;j<n;j++){
            for(int i=j+1;i<n;i++){
                dp[i][j]+=max({dp[i][j-1] , dp[i-1][j-1] , (i+1<n) ? dp[i+1][j-1] : 0});
            }
        }
        return child1collect + dp[n-2][n-1] + dp[n-1][n-2];
    }
};

// class Solution {
// public:
//     int n;
//     vector<vector<int>> dp;
//     int child1collect(vector<vector<int>>& fruits){
//         int count=0;
//         for(int i=0;i<n;i++) count+=fruits[i][i];
//         return count;
//     }
//     int child2collect(int i,int j,vector<vector<int>>& fruits){
//         if(i>=n or i<0 or j>=n or j<0) return 0;
//         if(i==n-1 and j==n-1) return 0;
//         if(i==j or i>j) return 0;
//         if(dp[i][j]!=-1) return dp[i][j];

//         int leftcorner = fruits[i][j] + child2collect(i + 1, j - 1, fruits);
//         int middle = fruits[i][j] + child2collect(i + 1, j, fruits);
//         int rightcorner = fruits[i][j] + child2collect(i + 1, j + 1, fruits);

//         return dp[i][j]= max({middle, rightcorner, leftcorner});
//     }
//     int child3collect(int i,int j,vector<vector<int>>& fruits){
//         if(i>=n or i<0 or j>=n or j<0) return 0;
//         if(i==n-1 and j==n-1) return 0;
//         if(i==j or i<j) return 0;
//         if(dp[i][j]!=-1) return dp[i][j];

//         int topcorner   = fruits[i][j] + child3collect(i - 1, j + 1, fruits);
//         int right       = fruits[i][j] + child3collect(i, j + 1, fruits);
//         int rightcorner = fruits[i][j] + child3collect(i + 1, j + 1, fruits);

//         return dp[i][j]=max({right, rightcorner, topcorner});
//     }
//     int maxCollectedFruits(vector<vector<int>>& fruits) {
//         n=fruits.size();
//         dp.resize(n,vector<int>(n,-1));
//         int firstchild=child1collect(fruits);
//         int secondchild=child2collect(0,n-1,fruits);
//         int thirdchild=child3collect(n-1,0,fruits);
//         return firstchild+secondchild+thirdchild;
//     }
// };