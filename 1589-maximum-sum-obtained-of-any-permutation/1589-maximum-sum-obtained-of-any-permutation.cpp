using ll=long long;
class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n=nums.size();
        const int MOD = 1e9 + 7;
        vector<int> diffArray(n+1,0);
        for(auto ele: requests){
            diffArray[ele[0]]+=1;
            diffArray[ele[1]+1]-=1;
        }
        for(int i=1;i<=n;i++) diffArray[i]+=diffArray[i-1];
        sort(begin(nums),end(nums),greater<int>());
        sort(begin(diffArray),begin(diffArray)+n,greater<int>());
        ll ans=0;
        for(int i=0;i<n;i++) ans=(ans+((ll)nums[i]*diffArray[i]))%MOD;
        return ans;
    }
};