class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int target=nums[i];
            int x=-1;
            for(int j=1;j<32;j++){
                if((nums[i] & (1<<j))>0) continue;
                x=(nums[i]^(1<<(j-1)));
                break;
            }
            if(nums[i]==2) ans.push_back(-1);
            else ans.push_back(x);
        }
        return ans;
    }
};