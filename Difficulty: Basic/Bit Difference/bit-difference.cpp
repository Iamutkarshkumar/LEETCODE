class Solution {
  public:
    int countBitsFlip(int a, int b) {
        int ans=0;
        while(a>0 or b>0){
            if((a&1)!=(b&1)) ans++;
            a>>=1;b>>=1;
        }
        return ans;
    }
};