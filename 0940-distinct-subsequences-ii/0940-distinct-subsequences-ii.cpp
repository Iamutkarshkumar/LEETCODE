class Solution {
public:
    using ll=long long;
    ll mod=1e9+7;
    vector<ll> dp;
    int n;
    ll solve(int i,string& s){
        if(i==n) return 1;
        if(dp[i]!=-1) return dp[i];


        ll ans=2*solve(i+1,s)%mod; //take + skip

        int j=i+1;
        while(j<n and s[i]!=s[j]) j++;
        if(j<n) ans = (ans-solve(j+1,s)+mod)%mod;
        return dp[i]=ans;
    }
    int distinctSubseqII(string s) {
        n=s.length();
        dp.assign(n+1,-1);
        return (solve(0,s)-1+mod)%mod;
    }
};