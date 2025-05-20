class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int mx=INT_MIN;
        int idx=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                mx=max(mx,abs(idx-i));
                idx=i+1;
            }
        }
        mx=max(mx,abs(n-idx));
        return mx;
    }
};