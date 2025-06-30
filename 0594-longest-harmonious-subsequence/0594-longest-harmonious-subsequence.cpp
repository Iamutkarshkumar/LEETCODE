class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) mp[nums[i]]++;
        int ans=0;
        sort(nums.begin(),nums.end());
        int i=0;
        while(i+1<n){
            if(abs(nums[i]-nums[i+1])==1) ans=max(ans,(mp[nums[i]]+mp[nums[i+1]]));
            i++;
        }
        return ans;
    }
};