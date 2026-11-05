class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans=0;
        for(int &ele1: arr1){
            bool flag=false;
            for(int &ele2: arr2){
                if(abs(ele1-ele2)<=d){
                    flag=true;
                    break;
                }
            }
            if(!flag) ans++;
        }
        return ans;
    }
};