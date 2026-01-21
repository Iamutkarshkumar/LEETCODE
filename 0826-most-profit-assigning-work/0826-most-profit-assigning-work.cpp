class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=profit.size(),m=worker.size();
        int ans=0;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++) v.push_back({difficulty[i],profit[i]});
        sort(begin(v),end(v));

        for(int i=1;i<n;i++)
            v[i].second=max(v[i].second,v[i-1].second);

        for(int w:worker){
            int idx=upper_bound(v.begin(),v.end(),make_pair(w,INT_MAX))-v.begin()-1;
            if(idx>=0) ans+=v[idx].second;
        }
        return ans;
    }
};
// class Solution {
// public:
//     int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
//         int ans=0;
//         priority_queue<pair<int,int>> pq;
//         for(int i=0;i<profit.size();i++) pq.push({profit[i],difficulty[i]});
//         sort(worker.begin(),worker.end(),greater<int>());

//         int i=0;

//         while(i<worker.size() && !pq.empty()){
//             auto [x,y]=pq.top();
//             if(y>worker[i]) pq.pop();
//             else{
//                 ans+=x;
//                 i++;
//             }
//         }
//         return ans;        
//     }
// };