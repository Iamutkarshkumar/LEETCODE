using ll=long long;
class Solution {
public:
    ll calcArea(ll x1,ll y1, ll x2, ll y2){
        ll len=min(x2-x1,y2-y1);
        return len*len;
    }
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        ll n=bottomLeft.size();
        ll ans=0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1=max(bottomLeft[i][0],bottomLeft[j][0]);
                int y1=max(bottomLeft[i][1],bottomLeft[j][1]);
                int x2=min(topRight[i][0],topRight[j][0]);
                int y2=min(topRight[i][1],topRight[j][1]);

                if(x2>x1 && y2>y1){
                    ans=max(ans,calcArea(x1,y1,x2,y2));
                }
            }
        }
        return ans;
    }
};