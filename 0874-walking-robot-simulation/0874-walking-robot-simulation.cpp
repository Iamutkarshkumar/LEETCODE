class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>> st;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for(auto ele: obstacles) st.insert({ele[0],ele[1]});

        int x=0,y=0,dir=0,maxDist=0;
        for(auto cmd : commands){
            if(cmd==-1) dir=(dir+1)%4;
            else if(cmd==-2) dir=(dir+3)%4;
            else{
                for(int i=0;i<cmd;i++){
                    int nextX = x+directions[dir].first;
                    int nextY = y+directions[dir].second;
                    if(st.count({nextX,nextY})) break;
                    else{
                        x=nextX,y=nextY;
                        maxDist=max(maxDist,x*x+y*y);
                    }
                }
            }
        }

        return maxDist;

    }
};