class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> s;
        int ans=n;
        for(int i=0;i<n;i++){
            int currSum=nums[i];
            s.clear();
            s.insert(nums[i]);
            for(int j=i+1;j<n;j++){
                currSum+=nums[j];
                s.insert(nums[j]);
                if(s.count(currSum)) ans++;
            }
        }
        return ans;
    }
};