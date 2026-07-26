//approach 1 : BS
// class Solution {
// public:
//     int BS(vector<vector<int>>& nums,int x){
//         int l=0,r=nums.size()-1;
//         int ans=0;
//         while(l<=r){
//             int mid=l+(r-l)/2;
//             if(nums[mid][0]>=x){
//                 ans=nums[mid][1];
//                 r=mid-1;
//             }
//             else l=mid+1;
//         }
//         return ans;
//     }
//     vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
//         vector<vector<int>> ans;
//         int n=series1.size();
//         int m=series2.size();
//         unordered_set<int> vis;
//         for(auto ele: series1){
//             int time=ele[0],val=ele[1];
//             int valInOther=BS(series2,time);
//             vis.insert(time);
//             ans.push_back({time,val+valInOther});
//         }
//         for(auto ele: series2){
//             int time=ele[0],val=ele[1];
//             if(vis.count(time)) continue;
//             int valInOther=BS(series1,time);
//             ans.push_back({time,val+valInOther});
//         }
//         sort(begin(ans),end(ans));
//         return ans;
//     }
// };
class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1,
                                            vector<vector<int>>& series2) {

        vector<vector<int>> ans;

        int n = series1.size(), m = series2.size();
        int i = 0, j = 0;

        while (i < n || j < m) {
            int t;

            if (j == m || (i < n && series1[i][0] < series2[j][0])) {
                t = series1[i][0];
            }
            else if (i == n || series2[j][0] < series1[i][0]) {
                t = series2[j][0];
            }
            else {
                t = series1[i][0];
            }

            while (i < n && series1[i][0] < t) i++;
            while (j < m && series2[j][0] < t) j++;

            long long v1 = (i < n) ? series1[i][1] : 0;
            long long v2 = (j < m) ? series2[j][1] : 0;

            ans.push_back({t, (int)(v1 + v2)});

            if (i < n && series1[i][0] == t) i++;
            if (j < m && series2[j][0] == t) j++;
        }

        return ans;
    }
};