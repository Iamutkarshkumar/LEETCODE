class Solution {
public:
    bool checkDivisibility(int n) {
        int temp=n;
        int sum=0,prod=1;
        while(temp){
            int x=temp%10;temp/=10;
            sum+=x;prod*=x;
        }
        if(n%(sum+prod)==0) return true;
        return false;
    }
};