class Solution {
public:
    int numSub(string s) {
        long long ans=0;
        int i=0;
        int n=s.length();
        while(i<n){
            if(s[i]=='1'){
                long long x=0;
                int j=i;
                while(j<n and s[j]=='1'){
                    x++;j++;
                }
                i=j;
                ans = (ans + ((x*(x+1))/2)%1000000007)%1000000007;
            }
            i++;
        }
        return ans%1000000007;
    }
};