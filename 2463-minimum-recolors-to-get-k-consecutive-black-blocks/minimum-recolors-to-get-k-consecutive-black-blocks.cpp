class Solution {
public:
    int countBlack(string x){
        int count=0;
        for(auto ele: x){
            if(ele=='B') count++;
        }
        return count;
    }
    int minimumRecolors(string blocks, int k) {
        int n=blocks.size();
        int ans=INT_MAX;
        for (int i=0;i<=n-k;i++){
            string window = blocks.substr(i, k);
            int blacks = countBlack(window);
            int recolors = k - blacks;
            ans = min(ans, recolors);
        }
        return ans;
    }
};