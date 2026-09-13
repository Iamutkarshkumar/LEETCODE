class Solution {
public:
    using pii=pair<int,int>;
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        vector<pii> v1,v2;
        for(int i=0;i<n;i++) for(int j=0;j<n;j++){
            if(img1[i][j]==1) v1.push_back({i,j});
        }
        for(int i=0;i<n;i++) for(int j=0;j<n;j++){
            if(img2[i][j]==1) v2.push_back({i,j});
        }
        map<pii,int> mp;
        for(auto ele1: v1){
            for(auto ele2: v2){
                int x1=ele1.first,y1=ele1.second;
                int x2=ele2.first,y2=ele2.second;
                pii temp={x1-x2,y1-y2};
                mp[temp]++;
            }
        }
        int ans=INT_MIN;
        for(auto ele: mp) ans=max(ans,ele.second);
        return ans==INT_MIN ? 0 : ans;
    }
};