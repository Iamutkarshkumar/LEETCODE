class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int ans=0;
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<profit.size();i++) pq.push({profit[i],difficulty[i]});
        sort(worker.begin(),worker.end(),greater<int>());

        int i=0;

        while(i<worker.size() && !pq.empty()){
            auto [x,y]=pq.top();
            if(y>worker[i]) pq.pop();
            else{
                ans+=x;
                i++;
            }
        }
        return ans;        
    }
};