class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]-i]++;
        }
        long long good=0;
        for(auto ele: mp){
            if(ele.second>1) good+=(1LL * ele.second * (ele.second - 1)) / 2;
        }
        long long total = (1LL * n * (n - 1)) / 2;
        return total-good;
    }
};
