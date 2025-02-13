class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int count=0;
        for(auto ele: nums) if(ele<k) count++;
        return count;
    }
};