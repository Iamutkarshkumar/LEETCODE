using ll=long long;
class Solution {
public:
    unordered_map<ll,ll> mp;
    int n;
    vector<ll> dp;
    ll solve(int i,vector<ll>& v){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        ll skip=solve(i+1,v);
        int j=lower_bound(begin(v)+i+1,end(v),v[i]+3)-begin(v);
        ll take=mp[v[i]]*v[i] +solve(j,v);
        return dp[i]=max(take,skip);
    }
    long long maximumTotalDamage(vector<int>& power) {
        for(auto ele: power) mp[ele]++;
        vector<ll> v(mp.size());
        for(auto ele: mp) v.push_back(ele.first);
        sort(begin(v),end(v));
        n=v.size();
        dp.assign(n+1,-1);
        return solve(0,v); 
    }
};