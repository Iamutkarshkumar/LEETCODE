class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1;

        while(l<r){
            int m=l+(r-l)/2;
            bool isEven=(r-m)%2==0;

            if(m+1<n && nums[m]==nums[m+1]){
                if(isEven) l=m+2;
                else r=m-1;
            }
            else if(m-1>=0 && nums[m]==nums[m-1]){
                if(isEven) r=m-2;
                else l=m+1;
            }
            else{
                return nums[m];
            }
        }
        return nums[l];
    }
};