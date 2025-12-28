class Solution {
public:
    int countNegatives(vector<vector<int>>& v) {
        int m=v.size();
        int n=v[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            int idx=upper_bound(v[i].begin(),v[i].end(),0,greater<int>())-v[i].begin();
            ans+=abs(n-idx);
        }
        return ans;
    }
};
// class Solution {
// public:
//     int neg(vector<int>& v){
//         int n=v.size();
//         int l=0,h=n-1;
//         int idx=n;
//         while(l<=h){
//             int m=l+(h-l)/2;
//             if(v[m]<0){
//                 idx=m;
//                 h=m-1;
//             }
//             else l=m+1;
//         }
//         return idx;
//     }
//     int countNegatives(vector<vector<int>>& grid) {
//         int l=grid[0].size();
//         int ans=0;
//         for(auto ele: grid){
//             int idx=neg(ele);
//             ans+=(l-idx);
//         }
//         return ans;
//     }
// };