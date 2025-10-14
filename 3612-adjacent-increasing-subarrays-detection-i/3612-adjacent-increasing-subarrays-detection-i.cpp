class Solution{
public:
    bool hasIncreasingSubarrays(vector<int>& nums,int k){
        int n=nums.size();
        vector<int> len(n);
        for(int i=0;i<n;i++) len[i]=(i>0 && nums[i-1]<nums[i])?len[i-1]+1:1;
        for(int s=0;s+2*k<=n;s++){
            if(len[s+k-1]>=k && len[s+2*k-1]>=k) return true;
        }
        return false;
    }
};
