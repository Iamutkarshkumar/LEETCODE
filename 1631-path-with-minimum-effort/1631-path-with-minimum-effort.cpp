using P=pair<int,pair<int,int>>;
class Solution {
public:
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    bool isSafe(int x,int y,int r,int c){
        return x>=0 and x<r and y>=0 and y<c;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row=heights.size(),col=heights[0].size();

        vector<vector<int>> result(row,vector<int>(col,INT_MAX));
        priority_queue<P,vector<P>,greater<P>> pq;
        result[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int ux=pq.top().second.first;
            int uy=pq.top().second.second;
            int diff=pq.top().first;
            pq.pop();
            for(auto dir: directions){
                int newx=ux+dir[0];
                int newy=uy+dir[1];
                if(isSafe(newx,newy,row,col)){
                    int abs_diff=abs(heights[newx][newy]-heights[ux][uy]);
                    int max_diff=max(diff,abs_diff);
                    if(max_diff<result[newx][newy]){
                        result[newx][newy]=max_diff;
                        pq.push({max_diff,{newx,newy}});
                    }
                }
            }
        }
        return result[row-1][col-1]==INT_MAX ? -1 : result[row-1][col-1];
    }
};