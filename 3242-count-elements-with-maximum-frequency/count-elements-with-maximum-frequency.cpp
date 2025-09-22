class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        int max_freq=INT_MIN;
        for(auto ele: nums) {
            mp[ele]++;
            max_freq=max(max_freq,mp[ele]);
        }
        
        // for(auto ele: mp) max_freq=max(max_freq,ele.second);
        int cnt=0;
        for(auto ele: mp){
            if(ele.second==max_freq) cnt++;
        }
        return cnt*max_freq;
    }
};