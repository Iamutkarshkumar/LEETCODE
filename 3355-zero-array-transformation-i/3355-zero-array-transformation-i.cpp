class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> diffArray(n+1,0);
        for(auto ele: queries){
            diffArray[ele[0]]+=1;
            diffArray[ele[1]+1]-=1;
        }
        for(int i=1;i<=n;i++) {
            diffArray[i]+=diffArray[i-1];
            if(nums[i-1]-diffArray[i-1]>0) return false;
        }
        return true;
    }
};