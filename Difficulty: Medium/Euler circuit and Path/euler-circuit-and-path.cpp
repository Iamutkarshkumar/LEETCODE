//Eularian path:
//a path that visits every edge exactly once
//not all graphs have Eulerian paths
//be careful from which vertex you start

//Eulerian Circuit:
// an EP that starts and ends at the same vertex
//also known as "Eulerian Cycle"
//not all graphs have Eulerian circuits
//if the graph has EC then you can start path/circuit from any vertex

//all vertices with non-zero degree are connected

//indegree importance:
// EC ---> all vertices have even indegree
// EP ---> exactly 0 or 2 vertices have odd indegree

//semi Eulerian Graph:
// a graph that has an Eulerian path but not an Eulerian circuit


//if odd deg count == 2 then it has an Eulerian path
//if odd deg count > 2 then it has no Eulerian path or circuit
//if odd deg count == 0 then it has an Eulerian circuit


class Solution {
  public:
    void DFS(int u, vector<int> adj[], vector<bool>& visited) {
        visited[u] = true;
        for (auto v : adj[u]) {
            if (!visited[v]) {
                DFS(v, adj, visited);
            }
        }
    }
    bool isConnected(int V, vector<int> adj[]){
        int nonZeroDegreeVertex = -1;
        for(int i=0;i<V;i++){
            if(adj[i].size()>0){
                nonZeroDegreeVertex = i;
                break;
            }
        }

        vector<bool> visited(V,false);
        DFS(nonZeroDegreeVertex,adj,visited);

        for(int i=0;i<V;i++){
            if(visited[i]==false and adj[i].size()>0){
                return false; // not all vertices with non-zero degree are connected
            }
        }
        return true; // all vertices with non-zero degree are connected
    }
    int isEulerCircuit(int V, vector<int> adj[]) {
        if(isConnected(V,adj)==false) return 0;

        int oddDegCount = 0;
        for(int i=0;i<V;i++){
            if(adj[i].size() % 2 != 0){
                oddDegCount++;
            }
        }
       
        if(oddDegCount > 2) return 0; // not an Eulerian path or circuit
        if(oddDegCount == 2) return 1; // Eulerian path exists
        if(oddDegCount == 0) return 2; // Eulerian circuit exists
    }
};