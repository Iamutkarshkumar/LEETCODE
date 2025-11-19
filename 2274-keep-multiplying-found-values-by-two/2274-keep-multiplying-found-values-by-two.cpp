class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(begin(nums),end(nums));
        for(auto ele: nums){
            if(ele==original) original*=2;
        }
        return original;
    }
};
// class Solution {
// public:
//     int findFinalValue(vector<int>& nums, int original) {
//         sort(begin(nums),end(nums));
//         bool flag=true;
//         while(flag){
//             if(binary_search(begin(nums),end(nums),original)) original*=2;
//             else flag=false;
//         }
//         return original;
//     }
// };