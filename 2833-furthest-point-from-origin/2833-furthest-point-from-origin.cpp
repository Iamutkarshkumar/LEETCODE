class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n=moves.length();
        int x=0,count=0;
        for(auto ele: moves){
            if(ele=='R'){
                x--;
                count++;
            } 
            else if(ele=='L'){
                x++;
                count++;
            }
        }
        if(x<0) x*=-1;
        return (n-count)+x;
    }
};