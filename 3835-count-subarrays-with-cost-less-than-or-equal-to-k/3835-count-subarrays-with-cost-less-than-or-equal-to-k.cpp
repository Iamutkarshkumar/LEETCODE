using ll=long long;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n=nums.size();
        ll ans=0;
        int l=0;
        deque<int> maxdq,mindq;
        for(int r=0;r<n;r++){
            while(!maxdq.empty() and nums[r]>maxdq.back()) maxdq.pop_back();
            maxdq.push_back(nums[r]);
            while(!mindq.empty() and nums[r]<mindq.back()) mindq.pop_back();
            mindq.push_back(nums[r]);

            while((ll)(maxdq.front()-mindq.front())*(r-l+1)>k){
                if(nums[l]==maxdq.front()) maxdq.pop_front();
                if(nums[l]==mindq.front()) mindq.pop_front();
                l++;
            }
            ans+=(r-l+1);
        }
        return ans;
    }
};