class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        queue<int> que;
        que.push(0);
        visited.insert(0);
        while(not que.empty()){
            int x=que.front();que.pop();

            for(auto nbr: rooms[x]){
                if(!visited.count(nbr)){
                    que.push(nbr);
                    visited.insert(nbr);
                }
            }
        }
        return visited.size()==rooms.size();
    }
};