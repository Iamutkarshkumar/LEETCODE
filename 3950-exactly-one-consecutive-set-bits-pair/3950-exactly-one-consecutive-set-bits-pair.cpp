class Solution {
public:
    bool consecutiveSetBits(int n) {
        int count=0;
        bool lastWasOne=false;
        while(n){
            if((n&1)==1 and lastWasOne) count++;
            else if((n&1)==1 and !lastWasOne) lastWasOne=true;
            else if((n&1)==0 and lastWasOne) lastWasOne=false;
            n>>=1;
        }
        return count==1;
    }
};