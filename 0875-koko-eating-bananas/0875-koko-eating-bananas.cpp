using ll=long long;
class Solution {
public:
    ll calcTime(vector<int>& piles, int m){
        ll ans=0;
        for(ll ele: piles) ans+=(ele + m - 1) / m;
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int maxele=*max_element(begin(piles),end(piles));
        int l=1,r=maxele;
        while(l<r){
            ll m=l+(r-l)/2;
            ll time=calcTime(piles,m);
            if(time<=h) r=m;
            else l=m+1;
        }
        return l;
    }
};