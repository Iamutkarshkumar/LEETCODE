class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int n=drones.size();
        int ansIdx=-1;
        int minDist=INT_MAX;
        int x1=target[0],y1=target[1];
        for(int i=0;i<n;i++){
            int x2=drones[i][0],y2=drones[i][1],range=drones[i][2];
            int manDist=abs(x1-x2)+abs(y1-y2);
            if(manDist<=range){
                if(manDist<minDist){
                    minDist=manDist;
                    ansIdx=i;
                }
            }
        }
        return ansIdx;
    }
};