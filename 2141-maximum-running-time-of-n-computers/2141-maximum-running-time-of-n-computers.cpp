using ll=long long;
class Solution {
public:
    ll sum=0;
    long long maxRunTime(int n, vector<int>& batteries) {
        for(auto ele: batteries) sum+=ele;
        ll ans;
        ll l=1,h=sum;
        while(l<=h){
            ll m=l+(h-l)/2;
            ll cur=0;
            for(int x:batteries) cur+=min((ll)x,m);
            if(m*n<=cur){
                ans=m;
                l=m+1;
            }
            else h=m-1;
        }
        return ans;
    }
};