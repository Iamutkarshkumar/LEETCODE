class Solution {
public:
    int numberOfPairs(vector<vector<int>>& p){
        int n=p.size(),ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                int xa=p[i][0],ya=p[i][1],xb=p[j][0],yb=p[j][1];
                // allow same row or same column (line) as valid; exclude identical points
                if(xa<=xb && ya>=yb && !(xa==xb && ya==yb)){
                    bool ok=true;
                    int xlo=min(xa,xb),xhi=max(xa,xb),ylo=min(ya,yb),yhi=max(ya,yb);
                    for(int k=0;k<n;k++){
                        if(k==i||k==j) continue;
                        int x=p[k][0],y=p[k][1];
                        if(x>=xlo && x<=xhi && y>=ylo && y<=yhi){ ok=false; break; }
                    }
                    if(ok) ans++;
                }
            }
        }
        return ans;
    }
};
