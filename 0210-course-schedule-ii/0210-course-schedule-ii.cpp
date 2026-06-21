class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>> adj(n);
        for(auto& ele : prerequisites){
            int u=ele[1],v=ele[0];
            adj[u].push_back(v);
        }

        vector<int> inDegree(n,0);
        for(vector<int>& vec:adj){
            for(int& node: vec){
                inDegree[node]++;
            }
        }
        vector<int> order;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(inDegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int u=q.front();q.pop();
            order.push_back(u);
            for(int& v: adj[u]){
                inDegree[v]--;
                if(inDegree[v]==0) q.push(v);
            }
        }
        if(order.size()==n) return order;
        return {};
    }
};