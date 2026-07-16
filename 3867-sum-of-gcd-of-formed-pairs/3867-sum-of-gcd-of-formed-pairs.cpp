using ll=long long;
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        ll n=nums.size();
        vector<ll> prefixGcd(n);
        ll currMax=LLONG_MIN;
        for(int i=0;i<n;i++){
            currMax=max(currMax,1LL*nums[i]);
            prefixGcd[i]=gcd(nums[i],currMax);
        } 
        sort(begin(prefixGcd),end(prefixGcd));
        for(auto ele: prefixGcd) cout<<ele<<" ";
        ll sum=0;
        for(int i=0;i<n/2;i++) sum+=gcd(prefixGcd[i],prefixGcd[n-1-i]);
        return sum;
    }
};