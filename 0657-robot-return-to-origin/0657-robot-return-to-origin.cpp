class Solution {
public:
    bool judgeCircle(string moves) {
        int u=0,r=0;
        for(auto ele: moves){
            if(ele=='U') u++;
            else if(ele=='D') u--;
            else if(ele=='R') r++;
            else if(ele=='L') r--;
        }
        return u==0 and r==0;
    }
};
// class Solution {
// public:
//     bool judgeCircle(string moves) {
//         int u=0,d=0,l=0,r=0;
//         for(auto ele: moves){
//             if(ele=='U') u++;
//             if(ele=='D') d++;
//             if(ele=='R') r++;
//             if(ele=='L') l++;
//         }
//         return (abs(u-d)+abs(r-l)==0);
//     }
// };