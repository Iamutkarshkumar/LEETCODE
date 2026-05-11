class Solution {
  public:
    int findPosition(int n) {
        // code here
        auto x=__builtin_popcount(n);
        if(x>1) return -1;
        int pos=1;
        while((n&1)==0){
            pos++;
            n>>=1;
        }
        return pos;
    }
};