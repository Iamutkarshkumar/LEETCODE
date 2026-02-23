using ll=long long;
class Solution {
public:
    ll fact(ll n){
        if(n<=1) return 1;
        ll ans=1;
        for(ll i=1;i<=n;i++) ans*=i;
        return ans;
    }
    bool isDigitorialPermutation(int n) {
        int ans=0;
        string s;
        s=to_string(n);
        sort(begin(s),end(s));
        int x=n;
        while(x){
            ans+=fact(x%10);
            x/=10;
        }
        string r=to_string(ans);
        sort(begin(r),end(r));
        cout<<ans;
        return r==s;
    }
};