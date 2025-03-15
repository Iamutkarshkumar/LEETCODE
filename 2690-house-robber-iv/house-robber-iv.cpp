class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int l=1,h=*max_element(nums.begin(),nums.end()),n=nums.size();
        while(l<h){
            int m = l+(h-l)/2;
            int x=0;
            for(int i=0;i<n;i++){
                if(nums[i]<=m){
                    x++;
                    i++;
                }
            }
            if(x>=k) h=m;
            else l=m+1;
        }
        return l;
    }
};