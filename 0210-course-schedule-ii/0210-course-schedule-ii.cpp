class Solution {
public:
    vector<int> topologicalOrder(unordered_map<int,vector<int>>& mp,int n,vector<int>& indegree){
        vector<int> ans;
        queue<int> que;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                que.push(i);
            }
        }

        while(!que.empty()){
            int u=que.front();
            que.pop(); 
            ans.push_back(u); 
            for(auto v: mp[u]){
                indegree[v]--;
                if(indegree[v]==0){
                  
                    que.push(v);
                }
            }
        }
        if(n!=ans.size()) return {};
        else{
            return ans;
        }  
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> mp;
        vector<int> indegree(numCourses,0);
        for(auto ele: prerequisites){
            int u=ele[1];
            int v=ele[0];

            // u------>v

            mp[u].push_back(v);
            indegree[v]++;
        }
        vector<int> ans;
        ans=topologicalOrder(mp,numCourses,indegree);
        return ans;
    }
};