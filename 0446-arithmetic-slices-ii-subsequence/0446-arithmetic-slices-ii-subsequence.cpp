class Solution {
public:
    using ll=long long;
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        vector<unordered_map<ll,ll>> v(n);
        ll ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                ll diff=(ll)nums[j]-(ll)nums[i];
                ll cnt = v[j].count(diff) ? v[j][diff] : 0;
                v[i][diff]+=cnt+1;
                ans+=cnt;
            }
        }
        return ans;
    }
};