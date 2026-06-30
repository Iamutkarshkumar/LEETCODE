class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        int a=0,b=0,c=0;
        int i=0,j=0;
        int ans=0;
        while(j<n){
            if(s[j]=='a') a++;
            if(s[j]=='b') b++;
            if(s[j]=='c') c++;

            while(a>0 && b>0 && c>0){
                ans+=(n-j);
                if(s[i]=='a') a--;
                if(s[i]=='b') b--;
                if(s[i]=='c') c--;
                i++;
            }
            j++;
        }
        return ans;
    }
};