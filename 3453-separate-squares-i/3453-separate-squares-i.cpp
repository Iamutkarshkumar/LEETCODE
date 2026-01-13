class Solution {
public:
    inline bool check(double m,const vector<vector<int>>& squares,double halfArea){
        double area=0;
        for(const auto& ele:squares){
            double y=ele[1],l=ele[2];
            if(y<m){
                area+=l*min(m-y,l);
                if(area>=halfArea) return true; // early stop
            }
        }
        return false;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double maxY=0,totalArea=0;
        for(const auto& ele:squares){
            double y=ele[1],l=ele[2];
            totalArea+=l*l;
            maxY=max(maxY,y+l);
        }

        double halfArea=totalArea*0.5;
        double l=0,r=maxY;

        while(r-l>1e-5){
            double m=l+(r-l)*0.5;
            if(check(m,squares,halfArea)) r=m;
            else l=m;
        }
        return r;
    }
};
