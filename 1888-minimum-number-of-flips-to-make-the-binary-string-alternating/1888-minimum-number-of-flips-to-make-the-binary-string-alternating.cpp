class Solution {
public:
    int n;
    vector<int> type2opr(string x){
        int c1=0,c2=0;
        for(int i=0;i<n;i++){
            if(x[i]!=(i%2==0?'0':'1')) c1++;
            if(x[i]!=(i%2==0?'1':'0')) c2++;
        }
        return {c1,c2};
    }
    int minFlips(string s) {
        n=s.length();
        s+=s;

        auto ele=type2opr(s.substr(0,n));
        int c1=ele[0],c2=ele[1];
        int ans=min(c1,c2);

        for(int i=1;i<n;i++){
            // remove left char
            if(s[i-1]!=( (i-1)%2==0?'0':'1')) c1--;
            if(s[i-1]!=( (i-1)%2==0?'1':'0')) c2--;

            // add right char
            if(s[i+n-1]!=( (i+n-1)%2==0?'0':'1')) c1++;
            if(s[i+n-1]!=( (i+n-1)%2==0?'1':'0')) c2++;

            ans=min(ans,min(c1,c2));
        }

        return ans;
    }
};