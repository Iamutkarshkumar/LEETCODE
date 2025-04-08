class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> seen;
        int idx=-1;
        for (int i=n-1;i>=0;i--){
            if (seen.find(nums[i]) != seen.end()) {
                idx=i;
                break;
            }
            seen.insert(nums[i]);
        }
        if (idx==-1) return 0;
        return (idx + 1 + 2) / 3;
    }
};