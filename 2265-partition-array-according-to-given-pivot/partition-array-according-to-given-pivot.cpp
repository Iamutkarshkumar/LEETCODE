class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> help;
        for(auto ele: nums) if(ele<pivot) help.push_back(ele);
        for(auto ele: nums) if(ele==pivot) help.push_back(ele);
        for(auto ele: nums) if(ele>pivot) help.push_back(ele);
        for(int i=0;i<nums.size();i++) nums[i]=help[i];
        return nums;
    }
};