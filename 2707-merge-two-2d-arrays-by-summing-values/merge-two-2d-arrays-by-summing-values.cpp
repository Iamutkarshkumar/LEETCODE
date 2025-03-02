class Solution {
public:
    static bool cmp(vector<int> a , vector<int> b){
        return a[0]<b[0];
    }
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        unordered_map<int,int> m;
        for(auto ele: nums1) m.insert(make_pair(ele[0],ele[1]));

        for(auto ele: nums2){
            if(m.find(ele[0])!=m.end()) m[ele[0]]+=ele[1];
            else  m.insert(make_pair(ele[0],ele[1]));
        }

        vector<vector<int>> ans;
        for(auto x: m) ans.push_back({x.first,x.second});
        sort(ans.begin(),ans.end(),cmp);
        return ans;
    }
};