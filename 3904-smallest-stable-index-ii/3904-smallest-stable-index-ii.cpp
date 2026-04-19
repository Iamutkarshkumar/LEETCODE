class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> maxx(n),minn(n);
        maxx[0]=nums[0],minn[n-1]=nums[n-1];
        for(int i=1;i<n;i++) maxx[i]=max(nums[i],maxx[i-1]);
        for(int i=n-2;i>=0;i--) minn[i]=min(nums[i],minn[i+1]);
        for(int i=0;i<n;i++){
            if(maxx[i]-minn[i]<=k) return i;
        }
        return -1;
    }
};