class Solution {
public:
    int largestInteger(int n, int s) {
        int numOf9 = s/9;
        int rem = s-numOf9*9;
        int count = rem==0 ? numOf9 : numOf9+1;
        if(n<count) return -1;
        int num=0;
        while(numOf9--){
            num=num*10 + 9;
        }
        if(rem>0) num=num*10+rem;
        int x=n-count;
        while(x--) num*=10;
        return num;
    }
};