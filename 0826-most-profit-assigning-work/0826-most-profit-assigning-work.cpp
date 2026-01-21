class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int ans=0;
        for(int i=0;i<worker.size();i++){
            int prof=0;
            for(int j=0;j<profit.size();j++){
                if(difficulty[j]<=worker[i]) prof=max(prof,profit[j]);
            }
            ans+=prof;
        }
        return ans;
    }
};