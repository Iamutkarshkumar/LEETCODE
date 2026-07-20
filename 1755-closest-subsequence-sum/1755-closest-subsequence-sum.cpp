class Solution {
public:
    using ll=long long;
    int minAbsDifference(vector<int>& nums, int goal) {
        ll n=nums.size();
        ll n1=n/2;
        ll n2=n-n1;
        vector<ll> sumsA(1<<n1),sumsB(1<<n2);
        for(int mask=0;mask<(1<<n1);mask++){
            ll s=0;
            for(int i=0;i<n1;i++){
                if(mask&(1<<i)) s+=nums[i];
            }
            sumsA[mask]=s;
        }
        for(int mask=0;mask<(1<<n2);mask++){
            ll s=0;
            for(int i=0;i<n2;i++){
                if(mask&(1<<i)) s+=nums[n1+i];
            }
            sumsB[mask]=s;
        }
        sort(begin(sumsB),end(sumsB));
        ll ans=LLONG_MAX;
        for(ll ele: sumsA){
            ll s=(ll)goal-ele;
            int idx=lower_bound(begin(sumsB),end(sumsB),s)-begin(sumsB);
            // The idea is that lower_bound only gives you one candidate, but the closest sum may be either the first element ≥ need or the element just before it.
            if(idx < sumsB.size())
                ans = min(ans, llabs(ele + sumsB[idx] - (ll)goal));

            if(idx > 0)
                ans = min(ans, llabs(ele + sumsB[idx-1] - (ll)goal));
        }
        return ans;
    }
};