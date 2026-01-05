using ll=long long;
class Solution {
public:
    ll calc(ll peak, ll len) {
        if (peak > len)
            return (peak + peak - len + 1) * len / 2;
        else
            return (peak + 1) * peak / 2 + (len - peak);
    }

    bool isValid(ll m, ll n, ll index, ll maxSum) {
        ll sum = m;
        sum += calc(m - 1, index);
        sum += calc(m - 1, n - index - 1);
        return sum <= maxSum;
    }
    int maxValue(int n, int index, int maxSum) {
        ll l=1,h=maxSum;
        ll ans;
        while(l<=h){
            ll m=l+(h-l)/2;
            if(isValid(m,n,index,maxSum)){
                ans=m;
                l=m+1;
            }
            else h=m-1;
        }
        return ans;
    }
};