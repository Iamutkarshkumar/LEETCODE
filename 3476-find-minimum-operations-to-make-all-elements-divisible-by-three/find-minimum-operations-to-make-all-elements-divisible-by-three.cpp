class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans=0;
        for(auto ele: nums) if(ele%3!=0) ans++;
        return ans;
    }
};