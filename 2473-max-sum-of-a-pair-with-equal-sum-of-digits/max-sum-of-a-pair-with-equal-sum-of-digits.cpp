class Solution {
public:
    int f(int n){
        string s=to_string(n);
        int ans=0;
        for(auto ele: s) ans+=ele-'0';
        return ans;
    }
    int maximumSum(vector<int>& nums) {
        int l=nums.size();
        unordered_map<int,int> mp;
        int maxSum=INT_MIN;
        for(int num: nums){
            int digitSum = f(num);
            if(mp.find(digitSum) != mp.end()){
                maxSum = max(maxSum, mp[digitSum] + num);
                mp[digitSum] = max(mp[digitSum], num); // Store the maximum value for this digit sum
            }
            else mp[digitSum] = num;
        }
        if(mp.size()==nums.size()) return -1;
        return maxSum;
    }
};