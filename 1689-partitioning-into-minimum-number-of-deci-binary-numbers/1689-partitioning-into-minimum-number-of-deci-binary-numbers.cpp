class Solution {
public:
    int minPartitions(string n) {
        int ans=0;
        for(auto ele: n){
            if(ele-'0'>ans) ans=ele-'0';
        }
        return ans;
    }
};
