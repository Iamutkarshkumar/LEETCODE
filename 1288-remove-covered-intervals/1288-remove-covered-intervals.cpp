class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals),end(intervals),cmp);
        int maxSoFar=INT_MIN;
        int ans=0;
        for(auto ele: intervals){
            if(ele[1]>maxSoFar){
                ans++;
                maxSoFar=ele[1];
            }
        }
        return ans;
    }
};