class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> visited;
        int n=nums.size();
        int i=0,j=0;
        while(j<n){
            if(j-i>k){
                visited.erase(nums[i]);
                i++;
            }
            
            if(visited.count(nums[j])) return true;
            
            visited.insert(nums[j]);
            j++;
        }
        return false;
    }
};