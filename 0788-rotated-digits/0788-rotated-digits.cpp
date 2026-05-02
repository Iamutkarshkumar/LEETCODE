class Solution {
public:
    bool help(int num){
        bool flag=false;
        while(num){
            int x=num%10;
            if(x==3 or x==4 or x==7) return false;
            if(x==2 or x==5 or x==6 or x==9) flag=true;
            num/=10;
        }
        return flag;
    }
    int rotatedDigits(int n) {
        int count=0;
        for(int i=1;i<=n;i++) count+=(help(i));
        return count;
    }
};