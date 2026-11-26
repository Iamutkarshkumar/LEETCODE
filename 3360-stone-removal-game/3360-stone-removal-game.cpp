class Solution {
public:
    bool canAliceWin(int n) {
        bool flag=false;
        int x=10;
        while(n){
            if(n<x) return flag;
            n-=x;
            x--;
            flag=!flag;
        }
        return flag;
    }
};