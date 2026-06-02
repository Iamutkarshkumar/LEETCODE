class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                           vector<int>& waterStartTime, vector<int>& waterDuration) {

        int n=landStartTime.size(),m=waterStartTime.size();
        int ans=INT_MAX;

        for(int i=0;i<n;i++){
            int landFinish=landStartTime[i]+landDuration[i];

            for(int j=0;j<m;j++){
                int waterFinish=max(landFinish,waterStartTime[j])+waterDuration[j];
                ans=min(ans,waterFinish);
            }
        }

        for(int i=0;i<m;i++){
            int waterFinish=waterStartTime[i]+waterDuration[i];

            for(int j=0;j<n;j++){
                int landFinish=max(waterFinish,landStartTime[j])+landDuration[j];
                ans=min(ans,landFinish);
            }
        }

        return ans;
    }
};