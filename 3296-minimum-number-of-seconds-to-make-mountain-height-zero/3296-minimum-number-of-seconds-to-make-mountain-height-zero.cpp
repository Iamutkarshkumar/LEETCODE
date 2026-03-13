using ll=long long;
class Solution {
public:
    ll help(ll x,ll mid,ll h){
        ll l=1,r=h,ans=0;
        while(l<=r){
            ll m=l+(r-l)/2;
            if(((m*(m+1))/2)*x<=mid){
                ans=m;
                l=m+1;
            }
            else r=m-1;
        }
        return ans;
    }
    bool possible(ll mid,int mountainHeight, vector<int>& workerTimes){
        int n=workerTimes.size();
        for(int i=0;i<n;i++){
            ll count=help(workerTimes[i],mid,mountainHeight);
            mountainHeight-=count;
        }
        return mountainHeight<=0;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        ll low=1,high=1e18,ans=0;
        while(low<=high){
            ll mid=low+(high-low)/2;
            if(possible(mid,mountainHeight,workerTimes)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};