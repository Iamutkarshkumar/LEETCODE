class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(begin(items),end(items));
        for(int i=1;i<items.size();i++)
            items[i][1]=max(items[i][1],items[i-1][1]);
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int ub=upper_bound(begin(items),end(items),vector<int>{queries[i],INT_MAX})-begin(items);
            ans.push_back(ub==0?0:items[ub-1][1]);

        }
        return ans;
    }
};