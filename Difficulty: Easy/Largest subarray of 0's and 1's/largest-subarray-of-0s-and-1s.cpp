class Solution {
  public:
    int maxLen(vector<int> &arr) {
        int n=arr.size(), sum=0, ans=0;
        unordered_map<int,int> mp;
        mp[0]=-1;                       // prefix sum 0 at index -1
        for(int i=0;i<n;i++){
            sum += arr[i]?1:-1;         // add +1 for 1, −1 for 0
            if(mp.count(sum))
                ans = max(ans, i-mp[sum]);
            else
                mp[sum] = i;
        }
        return ans;
    }
};