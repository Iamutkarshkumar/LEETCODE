class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int z=0,o=0,t=0;
        for(auto ele: stones){
            if(ele%3==0) z++;
            else if(ele%3==1) o++;
            else t++;
        }
        if(z%2==0) return o>=1 and t>=1;
        return abs(o-t)>2;
    }
};