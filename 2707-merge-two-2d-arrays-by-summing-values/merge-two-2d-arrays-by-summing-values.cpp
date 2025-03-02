class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& a, vector<vector<int>>& b) {
        int i=0,j=0;
        vector<vector<int>> ans;
        while(i<a.size() and j<b.size()){
            if(a[i][0]==b[j][0]){
                ans.push_back({a[i][0],a[i][1]+b[j][1]});
                i++;
                j++;
            } 
            else if(a[i][0]<b[j][0]){
                ans.push_back({a[i][0],a[i][1]});
                i++;
            }
            else if(a[i][0]>b[j][0]){
                ans.push_back({b[j][0],b[j][1]});
                j++;
            }
        }
        while(i<a.size()){
            ans.push_back({a[i][0],a[i][1]});
            i++;
        }
        while(j<b.size()){
            ans.push_back({b[j][0],b[j][1]});
            j++;
        }
        return ans;
    }
};
// class Solution {
// public:
//     static bool cmp(vector<int> a , vector<int> b){
//         return a[0]<b[0];
//     }
//     vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
//         unordered_map<int,int> m;
//         for(auto ele: nums1) m.insert(make_pair(ele[0],ele[1]));

//         for(auto ele: nums2){
//             if(m.find(ele[0])!=m.end()) m[ele[0]]+=ele[1];
//             else  m.insert(make_pair(ele[0],ele[1]));
//         }

//         vector<vector<int>> ans;
//         for(auto x: m) ans.push_back({x.first,x.second});
//         sort(ans.begin(),ans.end(),cmp);
//         return ans;
//     }
// };