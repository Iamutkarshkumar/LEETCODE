using ll=long long;
class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        ll n=nums.size();
        vector<ll> pref(n),suffMin(n);
        suffMin[n-1]=nums[n-1];
        int minele=nums[n-1];
        for(int i=n-2;i>=0;i--){
            minele=min(minele,nums[i]);
            suffMin[i]=minele;
        }
        pref[0]=nums[0];
        for(ll i=1;i<n;i++){
            pref[i]=nums[i]+pref[i-1];
        }

        long long ans=LLONG_MIN;
        for(ll i=0;i<n-1;i++){
            long long x= pref[i] - suffMin[i+1];
            ans=max(ans,x);
        }
        return ans;
    }
};