class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]*=2;
                nums[i+1]=0;
            }
        }
        vector<int> ans;
        int count=0;
        for(auto ele: nums){
            if(ele!=0){
                ans.push_back(ele);
                count++;
            }
        }
        count=abs(count-n);
        while(count--) ans.push_back(0);
        return ans;
    }
};