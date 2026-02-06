using ll=long long;
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        ll n=nums.size();
        sort(begin(nums),end(nums));
        ll ans=INT_MAX;
        for(int i=0;i<n-1;i++){
            ll x=(ll)k*nums[i];
            ll ub=upper_bound(begin(nums),end(nums),x)-begin(nums);
            ll remove=i+n-ub;
            ans=min(remove,ans);
        }
        return ans==INT_MAX ? 0 : ans;
    }
};