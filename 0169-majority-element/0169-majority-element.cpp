// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int count=0,candidate=0;
//         for(int i=0;i<nums.size();i++){
//             if(count==0) candidate=nums[i];
//             if(nums[i]==candidate) count++;
//             else count--;
//         }
//         return candidate;
//     }
// };
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n=nums.size();
        return ((n&1)==1 ? nums[n/2] : nums[(n/2)-1]);
    }
};