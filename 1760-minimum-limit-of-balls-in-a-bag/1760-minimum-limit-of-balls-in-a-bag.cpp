class Solution {
public:
    bool possible(int m,vector<int>& nums, int maxOperations){
        for(auto ele: nums){
            if(ele>m){
                int x=((ele+m-1)/m)-1;
                maxOperations-=x;
                if(maxOperations<0) return false;
            }
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l=1,r=*max_element(begin(nums),end(nums));
        int ans=0;
        while(l<=r){
            int m=l+(r-l)/2;
            if(possible(m,nums,maxOperations)){
                ans=m;
                r=m-1;
            }
            else l=m+1;
        }
        return ans;
    }
};