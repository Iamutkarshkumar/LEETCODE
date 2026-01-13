// class Solution {
// public:
//     double maxY=0,totalArea=0;
//     bool check(double m,vector<vector<int>>& squares){
//         double area =0;
//         for(auto ele: squares){
//             int y=ele[1],l=ele[2];
//             if(y<m){
//                 area+= l* min(m-y,l*1.0);
//             }
//         }
//         return area>=totalArea/2;
//     }
//     double separateSquares(vector<vector<int>>& squares) {
//         for(auto ele: squares){
//             int y=ele[1];
//             int l=ele[2];
//             totalArea+=1.0*l*l;
//             maxY=max(maxY,1.0*(y+l));
//         }
//         double l=0,r=maxY;
//         while(abs(l-r)>1e-5){
//             double m=l+(r-l)/2;
//             if(check(m,squares)) r=m;
//             else l=m;
//         }
//         return r;
//     }
// };
class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double max_y = 0, total_area = 0;
        for (auto& sq : squares) {
            int y = sq[1], l = sq[2];
            total_area += (double)l * l;
            max_y = max(max_y, (double)(y + l));
        }

        auto check = [&](double limit_y) -> bool {
            double area = 0;
            for (auto& sq : squares) {
                int y = sq[1], l = sq[2];
                if (y < limit_y) {
                    area += l * min(limit_y - y, (double)l);
                }
            }
            return area >= total_area / 2;
        };

        double lo = 0, hi = max_y;
        double eps = 1e-5;
        while (abs(hi - lo) > eps) {
            double mid = (hi + lo) / 2;
            if (check(mid)) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        return hi;
    }
};