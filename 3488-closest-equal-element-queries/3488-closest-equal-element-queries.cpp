class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,vector<int>> mp;
        int n=nums.size();

        for(int i=0;i<n;i++) mp[nums[i]].push_back(i);

        vector<int> ans;

        for(auto ele:queries){
            int x=nums[ele];
            vector<int>& pos=mp[x];

            if(pos.size()==1){
                ans.push_back(-1);
                continue;
            }

            int idx=lower_bound(pos.begin(),pos.end(),ele)-pos.begin();

            int next=pos[(idx+1)%pos.size()];
            int prev=pos[(idx-1+pos.size())%pos.size()];

            int d1=abs(next-ele);
            int d2=abs(ele-prev);

            d1=min(d1,n-d1);
            d2=min(d2,n-d2);

            ans.push_back(min(d1,d2));
        }

        return ans;
    }
};