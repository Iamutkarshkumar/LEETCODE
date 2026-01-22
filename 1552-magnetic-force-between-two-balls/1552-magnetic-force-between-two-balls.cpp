class Solution {
public:
    int n;
    bool possible(int mid,vector<int>& position,int m){
        int count=1;
        int prevBasket=position[0];
        for(int i=1;i<n;i++){
            if(position[i]-prevBasket >=mid){
                count++;
                prevBasket=position[i];
            }
            if(count==m) return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        n=position.size();
        sort(begin(position),end(position));
        int l=0,r=position[n-1]-position[0];
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(possible(mid,position,m)){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans;
    }
};