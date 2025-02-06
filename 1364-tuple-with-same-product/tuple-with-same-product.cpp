class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<long long,long long> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                mp[nums[i]*nums[j]]++;
            }
        }
        long long ans=0;
        for(auto ele: mp){
            long long count = ele.second;
            if (count > 1) {
                ans += (count * (count - 1) / 2) * 8;
            }
        }
        return ans;
    }
};