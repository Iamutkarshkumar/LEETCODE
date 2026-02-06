class Solution {
public:
    int countMonobit(int n) {
        int ans=1;
        int x=1;
        bool flag=true;
        while(flag){
            if(pow(2,x)-1<=n) ans++;
            else flag=false;
            x++;
        }
        return ans;
    }
};