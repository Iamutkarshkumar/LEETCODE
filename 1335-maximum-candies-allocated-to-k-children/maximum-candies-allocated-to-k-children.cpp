class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int mx=INT_MIN;for(auto ele: candies) mx = max(mx,ele);
        long long l=1,r=mx;
        long long ans=0;
        while(l<=r){
            long long m = l+(r-l)/2;
            long long x=0;
            for(auto ele: candies) x+= ele/m;
            if(x>=k){
                ans = m;
                l=m+1;
            }
            else r=m-1;
        }
        return ans;
    }
};