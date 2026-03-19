class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans(n,-1);
        vector<long long> pref(n);
        pref[0]=nums[0];
        for(int i=1;i<n;i++) pref[i] = pref[i-1]+nums[i];
        for(int i=k;i<(n-k);i++){
            long long sum=pref[i+k]-(i-k-1>=0?pref[i-k-1]:0);
            ans[i]=sum/(2*k+1);
        }
        return ans;
    }
};