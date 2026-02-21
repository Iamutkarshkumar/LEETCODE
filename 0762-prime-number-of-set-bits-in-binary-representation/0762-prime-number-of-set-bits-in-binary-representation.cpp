class Solution {
public:
    bool check(int x){
        return (x==2 or x==3 or x==5 or x==7 or x==11 or x==13 or x==17 or x==19);
    }
    int countPrimeSetBits(int left, int right) {
        int ans=0;
        for(int i=left;i<=right;i++){
            int x=__builtin_popcount(i);
            if(check(x)) ans++;
        }
        return ans;
    }
};