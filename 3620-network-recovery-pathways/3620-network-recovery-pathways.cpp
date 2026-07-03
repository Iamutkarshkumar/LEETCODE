using ll=long long;
using pll=pair<ll,ll>;
class Solution {
public: 
    bool check(ll n,vector<vector<pll>>& adj,ll mid,ll k){
        priority_queue<pll,vector<pll>,greater<pll>> pq;
        vector<ll> result(n,LLONG_MAX);
        result[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            ll u=pq.top().second;
            ll w=pq.top().first;
            pq.pop();
            if(w>result[u]) continue;
            for(auto node: adj[u]){
                ll v=node.first;
                ll wt=node.second;
                if(wt<mid) continue;
                if(wt+w<result[v]){
                    result[v]=wt+w;
                    pq.push({wt+w,v});
                }
            }
        }
        return result[n-1]!=LLONG_MAX && result[n-1]<=k;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        ll n=online.size();
        if(!online[0] || !online[n-1]) return -1;
        ll l=LLONG_MAX,r=0;
        vector<vector<pll>> adj(n);
        for(auto ele: edges){
            ll u=ele[0],v=ele[1],w=ele[2];
            if(online[u]==false or online[v]==false) continue;
            adj[u].push_back({v,w});
            l=min(l,w);
            r=max(r,w);
        }
        ll ans=-1;
        while(l<=r){
            ll mid=l+(r-l)/2;
            if(check(n,adj,mid,k)){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans;
    }
};