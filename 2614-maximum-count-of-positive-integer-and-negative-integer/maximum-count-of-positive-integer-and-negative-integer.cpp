class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=0,p=0;
        for(auto ele: nums){
            if(ele>0) p++;
            else if(ele<0) n++;
        }
        return max(n,p);
    }
};