class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n=nums.size();
        int x=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                x=i;
                break;
            }
        }
        for(int i=x+1;i<n;i++){
            if(nums[i]==1){
                if(i-x-1<k) return false;
                else x=i;
            }
        }
        return true;
    }
};