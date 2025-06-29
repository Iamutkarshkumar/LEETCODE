class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD=1e9+7;
        int n=nums.size(), ans=0;
        sort(nums.begin(), nums.end());
        vector<int> pow2(n);
        pow2[0]=1;
        for(int i=1;i<n;i++)
            pow2[i] = (pow2[i-1]*2ll) % MOD;
        int l=0, r=n-1;
        while(l<=r){
            if(nums[l]+nums[r] <= target){
                // all subsequences using nums[l] as min and any subset of nums[l+1..r] 
                ans = (ans + pow2[r-l]) % MOD;
                l++;
            } else {
                r--;
            }
        }
        return ans;
    }
};
