class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> s;
        for(int i=0;i<n;i++){
            if(s.count(nums[i])) return nums[i];
            s.insert(nums[i]);
        }
        return -1;
    }
};