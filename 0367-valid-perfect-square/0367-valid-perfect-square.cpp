class Solution {
public:
    int mySqrt(int x) {
        long long l=0,h=x;
        while(l<=h){
            long long m=l+(h-l)/2;
            if(m*m==x) return m;
            else if(m*m>x) h=m-1;
            else l=m+1;
        }
        return h;
    }
    bool isPerfectSquare(int num) {
       int x=mySqrt(num);
       return x*x==num; 
    }
};