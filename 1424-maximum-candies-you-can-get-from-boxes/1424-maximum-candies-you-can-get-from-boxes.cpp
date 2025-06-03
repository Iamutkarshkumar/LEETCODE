class Solution {
public:
    int maxCandies(vector<int>& status,
                   vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {
        int n=status.size(),res=0;
        vector<char> haveKey(n,0),haveBox(n,0),vis(n,0);
        queue<int>q;
        unordered_set<int> waiting;
        // take initial boxes
        for(int b:initialBoxes){
            haveBox[b]=1;
            if(status[b]){ q.push(b); vis[b]=1; }
            else waiting.insert(b);
        }
        // BFS
        while(!q.empty()){
            int b=q.front(); q.pop();
            res+=candies[b];
            // collect new keys
            for(int k:keys[b]){
                if(!haveKey[k]){
                    haveKey[k]=1;
                    if(haveBox[k] && !vis[k]){
                        q.push(k);
                        vis[k]=1;
                        waiting.erase(k);
                    }
                }
            }
            // collect contained boxes
            for(int nb:containedBoxes[b]){
                if(!haveBox[nb]){
                    haveBox[nb]=1;
                    if((status[nb] || haveKey[nb]) && !vis[nb]){
                        q.push(nb);
                        vis[nb]=1;
                    } else {
                        waiting.insert(nb);
                    }
                }
            }
        }
        return res;
    }
};
