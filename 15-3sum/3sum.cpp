class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;

        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;

            unordered_set<int> st;
            for(int j=i+1;j<n;j++){
                int rem=-(nums[i]+nums[j]);
                if(st.count(rem)){
                    ans.push_back({nums[i],nums[j],rem});
                    while(j+1<n && nums[j]==nums[j+1]) j++;
                }
                st.insert(nums[j]);
            }
        }
        return ans;
    }
};
