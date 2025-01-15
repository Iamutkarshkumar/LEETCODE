class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int count =__builtin_popcount(num2);//to count number of set bits
        int res=0;
        //cancel set bits from highest to lowest weight
        for(int i=31;i>=0 and count;i--){
            if(num1 & (1<<i)){
                count--;
                res+=(1<<i);
            }
        }

        //set bits lowest to highest weight
        for(int i=0;i<32 and count;i++){
            if((num1 & (1<<i))==0){
                count--;
                res+=(1<<i);
            }
        }
        return res;
    }
};