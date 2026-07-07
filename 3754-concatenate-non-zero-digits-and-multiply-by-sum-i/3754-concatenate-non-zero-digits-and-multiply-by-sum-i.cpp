class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum=0;
        int mul=1;
        long long x=0;
        while(n){
            int lastDigit=n%10;
            n/=10;
            if(lastDigit>0){
                sum+=lastDigit;
                x=lastDigit*mul+x;
                mul*=10;
            }
        }
        return x*sum;
    }
};