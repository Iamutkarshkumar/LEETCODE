class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> diffArray(n,0);
        for(auto& ele: queries){
            diffArray[ele[0]]+=1;
            if(ele[1]+1<n) diffArray[ele[1]+1]-=1;
        }
        int cummSum=0;
        for(int i=0;i<n;i++) {
            cummSum+=diffArray[i];
            if(nums[i]>cummSum) return false;
        }
        return true;
    }
};
