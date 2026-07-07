class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n=nums.size();
        int mid=nums[n/2];
        int count=0;
        for(auto ele: nums){
            if(ele-mid==0) count++;
        }
        return count==1;
    }
};