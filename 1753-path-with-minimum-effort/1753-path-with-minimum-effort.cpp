class Solution {
public:
    using P=pair<int,pair<int,int>>;
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    bool isSafe(int m,int n,int x,int y){
        return x>=0 and x<m and y>=0 and y<n;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();

        vector<vector<int>> result(m,vector<int>(n,INT_MAX));

        priority_queue<P,vector<P>,greater<P>> pq;

        result[0][0]=0;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            int diff=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();

            for(auto dir: directions){
                int x_=x+dir[0];
                int y_=y+dir[1];

                if(!isSafe(m,n,x_,y_)) continue;

                int abs_diff=abs(heights[x][y]-heights[x_][y_]);
                int max_diff=max(abs_diff,diff);
                
                if(max_diff< result[x_][y_]){
                    pq.push({max_diff,{x_,y_}});
                    result[x_][y_]= max_diff;
                }
            }
        }
        if(result[m-1][n-1] == INT_MAX)
            return -1;
        
        return result[m-1][n-1];
    }
};