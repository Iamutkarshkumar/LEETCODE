class Solution {
public:
    bool isTopologicalOrderPossible(unordered_map<int,vector<int>>& mp,int n,vector<int>& indegree){
        queue<int> que;
        int count=0;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){ 
                count++;
                que.push(i);
            }
        }

        while(!que.empty()){
            int curr=que.front();
            que.pop();

            for(auto v: mp[curr]){
                indegree[v]--;
                if(indegree[v]==0){
                    count++;
                    que.push(v);
                }
            }
        }
        return count==n;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> mp;
        vector<int> indegree(numCourses,0);
        for(auto ele: prerequisites){
            int u=ele[1];
            int v=ele[0];
            // u------>v
            mp[u].push_back(v);
            indegree[v]++;
        }

        return isTopologicalOrderPossible(mp,numCourses,indegree);
    }
};