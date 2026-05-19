class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        for(auto ele: nums1){
            if(binary_search(begin(nums2),end(nums2),ele)) return ele;
        }
        return -1;
    }
};