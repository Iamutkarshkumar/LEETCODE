class Solution {
public:
    bool isPalindromic(string s) {
        string help = "";
        for (char ch : s) {
            int i=7;
            while(i>=0){
                help+=((ch>>i)&1) + '0';
                i--;
            }
        }
        int i=0,n=help.length();
        for(int i=0;i<=n/2;i++){
            if(help[i]!=help[n-1-i]) return false;
        }
        return true;
    }
};