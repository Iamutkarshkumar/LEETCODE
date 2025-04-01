class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(auto ele: nums) ans^=ele;
        for(int i=0;i<=n;i++) ans^=i;
        return ans;
    }
};