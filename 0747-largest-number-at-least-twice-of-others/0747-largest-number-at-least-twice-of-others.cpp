class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n=nums.size();
        int mx=*max_element(begin(nums),end(nums));
        int idx=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==mx){
                idx=i;
            }
            else if(nums[i]*2>mx) return -1;
        }
        return idx;
    }
};