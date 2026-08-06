class Solution {
public:
    int prod(int x){
        int p=1;
        while(x){
            p*=(x%10);
            x/=10;
        }
        return p;
    }
    int smallestNumber(int n, int t) {
        bool flag=true;
        while(flag){
            int p=prod(n);
            if(p%t==0) return n;
            n++;
        }
        return -1;
    }
};