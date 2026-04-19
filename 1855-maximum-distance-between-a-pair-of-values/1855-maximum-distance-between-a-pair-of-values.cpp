// class Solution {
// public:
//     int maxDistance(vector<int>& nums1, vector<int>& nums2) {
//         int n=nums1.size(),m=nums2.size();
//         int ans=0;
//         for(int i=0;i<n;i++){
//             int idx=upper_bound(nums2.begin()+i,nums2.end(),nums1[i],greater<int>())-nums2.begin()-1;
//             ans=max(ans,idx-i);
//         } 
//         return ans;
//     }
// };
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0;
        int n=nums1.size(),m=nums2.size();
        int ans=0;
        while (i<n && j<m) {
            if (nums1[i] <= nums2[j]) {
                ans = max(ans, j - i);
                j++;
            } 
            else{
                i++;
                if (i > j) j = i;
            }
        }
        return ans;
    }
};