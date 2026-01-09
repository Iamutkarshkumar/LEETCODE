class Solution {
public:
    int n;
    int countPairs(vector<int>& nums, int m){
        int count=0;
        int i=0;
        while(i+1<n){
            if((nums[i+1]-nums[i])<=m){
                count++;
                i+=2;
            }
            else i++;
        }
        return count;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(begin(nums),end(nums));
        n=nums.size();
        int l=0,r=nums[n-1]-nums[0];
        int ans;
        while(l<=r){
            int m=l+(r-l)/2;
            int count=countPairs(nums,m);
            if(count>=p){
                ans=m;
                r=m-1;
            }
            else l=m+1;
        }
        return ans;
    }
};