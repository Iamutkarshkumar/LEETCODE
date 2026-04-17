class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n=nums.size();
        vector<int> rev;
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
            string s=to_string(nums[i]);
            reverse(begin(s),end(s));
            int x=stoi(s);
            rev.push_back(x);
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int ele=rev[i];
            vector<int> &v=mp[ele];
            int ub=upper_bound(begin(v),end(v),i)-begin(v);
            if(ub==v.size()) continue;
            int idx=v[ub];
            ans=min(ans,abs(idx-i));
        }
        return ans==INT_MAX ? -1 : ans;
    }
};