class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            unordered_set<int> seen; // Reset for every new starting index
            for (int j = i; j < n; j++) {
                seen.insert(nums[j]);
                int distinct = seen.size();
                ans += (distinct * distinct);
            }
        }
        
        return ans;
    }
};
// class Solution {
// public:
//     int sumCounts(vector<int>& nums) {
//         int n=nums.size();
//         int ans=0;
//         unordered_set<int> st;
//         for(int i=0;i<n;i++){
//             for(int j=i;j<n;j++){
//                 for(int idx=i;idx<=j;idx++) st.insert(nums[idx]);
//                 int sz=st.size();
//                 ans+=(sz*sz);
//                 st.clear();
//             }
//         }
//         return ans;
//     }
// };