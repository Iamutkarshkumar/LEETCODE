class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                for(int idx=i;idx<=j;idx++) st.insert(nums[idx]);
                int sz=st.size();
                ans+=(sz*sz);
                st.clear();
            }
        }
        return ans;
    }
};