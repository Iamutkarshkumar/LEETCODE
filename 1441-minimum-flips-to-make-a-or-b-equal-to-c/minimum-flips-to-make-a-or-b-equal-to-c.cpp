class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        while (a > 0 or b > 0 or c > 0) {
            int abit = a & 1;
            int bbit = b & 1;
            int cbit = c & 1;
            
            if ((abit | bbit) != cbit) {
                if (cbit == 1) ans += 1;      
                else ans += abit + bbit;       
            }
            
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return ans;
    }
};
