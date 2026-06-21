// class Solution {
//   public:
//     void DFS(vector<vector<int>>& adj,int u,vector<bool>& visited,stack<int>& st){
//         visited[u]=true;
//         for(int v: adj[u]){
//             if(!visited[v]) DFS(adj,v,visited,st);
//         }
//         st.push(u); // pehele mere baccho ko stack mein daalo uske baad stack mein daalo
//         // when you return/backtrack then push that node to stack
//     }
//     vector<int> topoSort(int V, vector<vector<int>>& edges) {
//         vector<vector<int>> adj(V);
//         for(auto ele: edges) adj[ele[0]].push_back(ele[1]);
        
//         vector<bool> visited(V,false);
//         stack<int> st;
        
//         for(int i=0;i<V;i++){
//             if(!visited[i]) DFS(adj,i,visited,st);
//         }
        
//         vector<int> ans;
//         while(!st.empty()){
//             ans.push_back(st.top());
//             st.pop();
//         }
//         return ans;
//     }
// };
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto ele: edges) adj[ele[0]].push_back(ele[1]);
        vector<int> inDegree(V,0);
        for(vector<int>& ele: adj){
            for(auto node: ele){
                inDegree[node]++;
            }
        }
        queue<int> q;
        for(int u=0;u<V;u++){
            if(inDegree[u]==0) q.push(u); 
        }
        
        vector<int> ans;
        while(!q.empty()){
            int u=q.front();q.pop();
            ans.push_back(u);
            for(int v: adj[u]){
                inDegree[v]--;
                if(inDegree[v]==0) q.push(v);
            }
        }
        return ans;
    }
};