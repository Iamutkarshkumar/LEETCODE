class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int i=start,j=start,n=nums.size();
        while(i>=0 and nums[i]!=target) i--;
        while(j<n and nums[j]!=target) j++;
        if(i<0) return abs(start-j);
        else if(j==n) return abs(start-i);
        return min(abs(start-i),abs(start-j));  
    }
};