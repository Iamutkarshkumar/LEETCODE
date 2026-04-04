//method 1
// class Solution {
// public:
//     int maxSubarrayLength(vector<int>& nums, int k) {
//         int n=nums.size(),ans=0;
//         unordered_map<int,int> mp;
//         int i=0,j=0;
//         while(j<n){
//             mp[nums[j]]++;
//             while(mp[nums[j]]>k){
//                 mp[nums[i]]--;
//                 i++;
//             }
//             ans=max(ans,(j-i+1));
//             j++;
//         }
//         return ans;
//     }
// };

//method 2
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size(),ans=0;
        unordered_map<int,int> mp;
        int culprit=0;
        int i=0,j=0;
        while(j<n){
            mp[nums[j]]++;
            if(mp[nums[j]]==k+1) culprit++;
            if(culprit>0){
                mp[nums[i]]--;
                if(mp[nums[i]]==k) culprit--;
                i++;
            }
            if(culprit==0) ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};