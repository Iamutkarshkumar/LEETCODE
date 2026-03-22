class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size(),i=0,j=0;
        vector<int> ans;
        deque<int> dq;

        for(int i=0;i<n;i++){
            while(dq.size()>0 and nums[dq.back()]<nums[i]) dq.pop_back();
            while(dq.size()>0 and dq.front()<=i-k) dq.pop_front();
            dq.push_back(i);
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         int n=nums.size(),i=0,j=0;
//         vector<int> ans;
//         deque<int> dq;

//         while(j<n){
//             // remove smaller elements from back
//             while(dq.size()>0 && nums[dq.back()]<nums[j]){
//                 dq.pop_back();
//             }

//             dq.push_back(j);

//             // remove out of window index
//             if(dq.front()<i){
//                 dq.pop_front();
//             }

//             // window of size k
//             if(j-i+1==k){
//                 ans.push_back(nums[dq.front()]);
//                 i++;
//             }

//             j++;
//         }
//         return ans;
//     }
// };