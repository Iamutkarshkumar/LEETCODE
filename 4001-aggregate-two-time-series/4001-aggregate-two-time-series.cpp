class Solution {
public:
    int BS(vector<vector<int>>& nums,int x){
        int l=0,r=nums.size()-1;
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid][0]>=x){
                ans=nums[mid][1];
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        vector<vector<int>> ans;
        int n=series1.size();
        int m=series2.size();
        unordered_set<int> vis;
        for(auto ele: series1){
            int time=ele[0],val=ele[1];
            int valInOther=BS(series2,time);
            vis.insert(time);
            ans.push_back({time,val+valInOther});
        }
        for(auto ele: series2){
            int time=ele[0],val=ele[1];
            if(vis.count(time)) continue;
            int valInOther=BS(series1,time);
            ans.push_back({time,val+valInOther});
        }
        sort(begin(ans),end(ans));
        return ans;
    }
};