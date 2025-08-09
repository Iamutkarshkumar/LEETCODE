class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> last_idx(n,-1);
        int last_chosen_index=0;
        int max_len=1;

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        last_idx[i]=j;
                    }
                    if(dp[i]>max_len){
                        max_len=dp[i];
                        last_chosen_index=i;
                    }
                }
            }
        }
        vector<int> ans;
        while(last_chosen_index!=-1){
            ans.push_back(nums[last_chosen_index]);
            last_chosen_index=last_idx[last_chosen_index];
        }
        return ans;
    }
};