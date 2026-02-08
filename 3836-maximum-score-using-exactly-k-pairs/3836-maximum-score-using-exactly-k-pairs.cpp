using ll=long long;
class Solution {
public:
    ll n,m;
    ll solve(int i,int j,int k,vector<int>& nums1, vector<int>& nums2,vector<vector<vector<ll>>>& dp){
        if(k==0) return 0;
        if(i==n or j==m) return LLONG_MIN;
        if(n-i<k or m-j<k) return LLONG_MIN;
        if(dp[i][j][k]!=LLONG_MIN) return dp[i][j][k];
        ll opr1=solve(i+1,j,k,nums1,nums2,dp);
        ll opr2=solve(i,j+1,k,nums1,nums2,dp);
        ll opr3=solve(i+1,j+1,k-1,nums1,nums2,dp);
        if(opr3!=LLONG_MIN) opr3+=(ll)nums1[i]*nums2[j];
        return dp[i][j][k]=max({opr1,opr2,opr3});
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        n=nums1.size();
        m=nums2.size();
        vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(m,vector<ll>(k+1,LLONG_MIN)));
        return solve(0,0,k,nums1,nums2,dp);
    }
};