class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum=nums[0],n=nums.size();
        if(n==1) return sum+1;
        int i=1;
        while(i<n and nums[i]-nums[i-1]==1){
            sum+=nums[i];
            i++;
        }
        sort(begin(nums),end(nums));
        while(true){
            if(binary_search(begin(nums),end(nums),sum)==false) return sum;
            sum++;
        }
        return 0;
    }
};