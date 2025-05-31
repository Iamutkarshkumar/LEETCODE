class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<long long,int> mp;
        long long sum =0;
        int ans =0;
        mp[0] =-1;                            
        for(int i=0;i<arr.size();i++){
            sum += arr[i];
            if(mp.find(sum)==mp.end())       
                mp[sum] = i;
            auto it = mp.find(sum - k);
            if(it != mp.end())
                ans = max(ans, i - it->second);
        }
        return ans;
    }
};