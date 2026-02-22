class Solution {
public:
    int binaryGap(int n) {
        int ans=0;
        int last=-1;   
        int pos=0;  
        
        while(n){
            if(n&1){
                if(last!=-1) ans=max(ans,pos-last);
                last=pos;
            }
            pos++;
            n>>=1;
        }
        return ans;
    }
};