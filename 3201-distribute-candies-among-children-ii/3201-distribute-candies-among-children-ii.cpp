class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans=0;
        for(int i=0;i<=limit && i<=n;i++){
            int low = max(0,n-i-limit);
            int high = min(limit,n-i);
            if(high>=low) ans+=(high-low+1);
        }
        return ans;
    }
};