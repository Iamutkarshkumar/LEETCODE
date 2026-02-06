class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxVal=*max_element(begin(nums),end(nums));
        vector<int> v(maxVal+2,0);
        unordered_map<int,int> mp;
        for(int x:nums){
            mp[x]++;
            int l=max(0,x-k);
            int r=min(maxVal,x+k);
            v[l]++;
            v[r+1]--;
        } 
        int ans=1;
        for(int i=0;i<=maxVal;i++){
            v[i]+=(i>0?v[i-1]:0);
            int targetFreq=mp[i];
            int needConversion = v[i] - targetFreq;

            int maxPossibleFreq = min(needConversion, numOperations);

            ans = max(ans, targetFreq + maxPossibleFreq);
        }
        return ans;
    }
};