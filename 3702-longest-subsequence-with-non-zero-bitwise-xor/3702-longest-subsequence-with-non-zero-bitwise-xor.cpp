class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        bool allZero=true;
        int xorr=0;
        for(int ele: nums){
            xorr^=ele;
            if(ele!=0) allZero=false;
        }
        if(xorr!=0) return n;
        if(allZero) return 0;
        else return n-1;
    }
};