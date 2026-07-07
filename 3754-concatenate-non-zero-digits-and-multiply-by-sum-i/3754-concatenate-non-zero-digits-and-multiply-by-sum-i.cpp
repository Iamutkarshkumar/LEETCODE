class Solution {
public:
    using ll=long long;
    long long sumAndMultiply(int n) {
        ll sum=0;
        ll mul=1;
        ll x=0;
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