using ll=long long;
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        ll n=nums.size();
        // vector<ll> prefixGcd(n);
        ll currMax=LLONG_MIN;
        for(auto &ele: nums){
            currMax=max(currMax,1LL*ele);
            ele=gcd(ele,currMax);
        } 
        sort(begin(nums),end(nums));
        ll sum=0;
        for(int i=0;i<n/2;i++) sum+=gcd(nums[i],nums[n-1-i]);
        return sum;
    }
};