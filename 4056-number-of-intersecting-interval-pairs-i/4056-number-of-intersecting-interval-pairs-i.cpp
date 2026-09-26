class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals),end(intervals));
        int ans=0;
        int n=intervals.size();
        for(int i=0;i<n;i++) for(int j=i+1;j<n;j++){
            if(intervals[j][0]<=intervals[i][1]) ans++;
        }
        return ans;
    }
};