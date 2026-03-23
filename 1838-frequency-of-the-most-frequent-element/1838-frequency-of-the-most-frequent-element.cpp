using ll=long long;
class Solution {
public:
    vector<ll> prefSum;

    ll BS(ll target_idx,vector<int>& nums,ll k){
        ll low=0,high=target_idx;
        ll ans=1;

        while(low<=high){
            ll mid=low+(high-low)/2;

            ll windowSize=target_idx-mid+1;
            ll reqWindowSum=windowSize*nums[target_idx];

            ll currWindowSum=prefSum[target_idx]-(mid>0?prefSum[mid-1]:0);

            ll operations=reqWindowSum-currWindowSum;

            if(operations<=k){
                ans=windowSize;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }

    int maxFrequency(vector<int>& nums,int k){
        ll n=nums.size();
        sort(nums.begin(),nums.end());

        prefSum.assign(n,0);
        prefSum[0]=nums[0];

        for(int i=1;i<n;i++){
            prefSum[i]=prefSum[i-1]+nums[i];
        }

        ll ans=1;

        for(ll target_idx=0;target_idx<n;target_idx++){
            ll freq=BS(target_idx,nums,k);
            ans=max(ans,freq);
        }

        return ans;
    }
};