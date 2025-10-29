class Solution {
public:
    int smallestNumber(int n) {
        int count=0;
        while(n){
            count++;
            n>>=1;
        }
        int ans=0;
        while(count--){ 
            ans<<=1;
            ans=ans|1;
        }
        return ans;
    }
};