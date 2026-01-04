class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n=nums.size();
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            if(ans[index[i]]==-1) ans[index[i]]=nums[i];
            else{
                reverse(ans.begin()+index[i],ans.end());
                ans.push_back(nums[i]);
                reverse(ans.begin()+index[i],ans.end());
            }
        }
        for(int i=0;i<n;i++) nums[i]=ans[i];
        return nums;
    }
};