class Solution {
public:
    using ll=long long;
    long long maxAlternatingSum(vector<int>& nums) {
        ll ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0) nums[i]*=-1;
        }
        sort(begin(nums),end(nums));
        int pos=(n+1)/2;
        int i=n-1;
        while(pos--){
            ans+=(nums[i]*nums[i]);
            i--;
        }
        while(i>=0){
            ans-=(nums[i]*nums[i]);
            i--;
        }
        return ans;
    }
};