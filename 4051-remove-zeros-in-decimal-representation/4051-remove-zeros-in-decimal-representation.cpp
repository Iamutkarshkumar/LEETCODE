class Solution {
public:
    long long removeZeros(long long n) {
        long long factor=1;
        long long ans=0;
        while(n){
            long long x=n%10;
            n/=10;
            if(x>0){
                ans+=(x*factor);
                factor*=10;
            }
        }
        return ans;
    }
};