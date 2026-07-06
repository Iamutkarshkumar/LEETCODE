class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        
        stack<int> st;
        st.push(nums2[0]);
        int j=1;
        while(j<nums2.size()){
            while(st.size()!=0 and nums2[j]>st.top()){
                int ele=st.top();
                st.pop();
                mp[ele]=nums2[j];
            }
            st.push(nums2[j]);
            j++;
        }
        vector<int> ans;
        for(auto ele: nums1){
            if(mp.count(ele)==0) ans.push_back(-1);
            else ans.push_back(mp[ele]);
        }
        return ans;
    }
};