class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        sort(begin(sides),end(sides));
        int a=sides[0],b=sides[1],c=sides[2];

        if(a+b<=c) return {};

        double x=acos((1.0*(b*b+c*c-a*a))/(2.0*b*c));
        double y=acos((1.0*(a*a+c*c-b*b))/(2.0*a*c));
        double z=acos((1.0*(a*a+b*b-c*c))/(2.0*a*b));

        double deg=180.0/acos(-1);

        vector<double> ans{x*deg,y*deg,z*deg};
        sort(begin(ans),end(ans));
        return ans;
    }
};