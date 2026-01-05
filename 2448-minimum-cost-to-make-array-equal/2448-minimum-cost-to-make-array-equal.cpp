using ll=long long;
class Solution {
public:
    ll calcCost(ll m,vector<int>& nums, vector<int>& cost){
        ll ans = 0;
        for(int i=0;i<nums.size();i++){
            ans+=(llabs(m-nums[i]))*cost[i];
        }
        return ans;
    }
    ll minCost(vector<int>& nums, vector<int>& cost) {
        ll l=*min_element(begin(nums),end(nums));
        ll r=*max_element(begin(nums),end(nums));
        ll ans = LLONG_MAX;
        while(l<=r){
            ll m=l+(r-l)/2;
            ll forM=calcCost(m,nums,cost);
            ll forMplusOne=calcCost(m+1,nums,cost);
            ans=min(ans,forM);
            if(forM<forMplusOne) r=m-1;
            else l=m+1;
        }
        return ans;
    }
};