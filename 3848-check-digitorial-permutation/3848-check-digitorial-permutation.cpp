using ll=long long;
class Solution {
public:
    bool isDigitorialPermutation(int n) {
        vector<int> dp(10,1);
        for(int i=1;i<10;i++) dp[i]=dp[i-1]*i;
        int ans=0;
        string s;
        s=to_string(n);
        sort(begin(s),end(s));
        int x=n;
        while(x){
            ans+=dp[(x%10)];
            x/=10;
        }
        string r=to_string(ans);
        sort(begin(r),end(r));
        cout<<ans;
        return r==s;
    }
};