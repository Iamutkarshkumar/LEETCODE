using ll=long long;
class Solution {
public:
    bool possible(ll m,ll k,vector<int>& nums,vector<ll>& prefix,ll n){
        int i=0,j=m-1;
        while(j<n){
            ll targetIdx=(i+j)/2;
            ll target=nums[targetIdx];

            ll operationsLeft=0;
            ll operationsRight=0;
            if(targetIdx==0) operationsLeft=0;
            else operationsLeft = abs(((targetIdx-i)*target) - (prefix[targetIdx-1]- (i>0 ? prefix[i-1] : 0)));

            operationsRight = abs(((j-targetIdx)*target) - (prefix[j]-prefix[targetIdx]));

            if(operationsLeft+operationsRight<=k) return true;

            i++;j++;
        }
        return false;
    }
    int maxFrequencyScore(vector<int>& nums, long long k) {
        sort(begin(nums),end(nums));
        ll n=nums.size();
        vector<ll> prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++) prefix[i]=nums[i]+prefix[i-1];
        ll l=1,r=n;
        ll ans=1;
        while(l<=r){
            ll m=l+(r-l)/2;
            if(possible(m,k,nums,prefix,n)){
                ans=m;
                l=m+1;
            }
            else r=m-1;
        }
        return ans;
    }
};