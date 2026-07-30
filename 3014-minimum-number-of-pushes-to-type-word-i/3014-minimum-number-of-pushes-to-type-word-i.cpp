class Solution {
public:
    int minimumPushes(string word) {
        int len=word.length();
        int x=len/8;
        int y=len%8;
        int ans=4*(x*(x+1));
        ans+=(x+1)*y;
        return ans;
    }
};