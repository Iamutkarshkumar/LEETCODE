class Solution {
public:
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    bool isSafe(int m,int n,int x,int y){
        return x>=0 and x<m and y>=0 and y<n;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size();
        int n=maze[0].size();
        queue<pair<int,int>> que;
        que.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]]='+';
        int lvl=0;
        while(!que.empty()){
            int w=que.size();
            while(w--){
                auto [x,y] = que.front();
                que.pop();
                if(!(x==entrance[0] and y==entrance[1]) and (x==0 or x==m-1 or y==0 or y==n-1)) return lvl;

                for(auto dir: directions){
                    int x_=dir[0]+x;
                    int y_=dir[1]+y;
                    if(isSafe(m,n,x_,y_) and maze[x_][y_]=='.'){
                        maze[x_][y_]='+';
                        que.push({x_,y_});
                    }
                }
            }
            lvl++;   
        }
        return -1;
    }
};
