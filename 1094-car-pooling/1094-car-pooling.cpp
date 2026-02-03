class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> mp;
        for(auto ele: trips){
            mp[ele[1]]+=ele[0];
            mp[ele[2]]+=-1*ele[0];
        }
        int sum=0;
        for(auto ele: mp){
            sum+=ele.second;
            if(sum>capacity) return false;
        }
        return true;
    }
};