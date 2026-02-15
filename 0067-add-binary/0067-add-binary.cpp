class Solution {
public:
    char logic(char x,char y,bool& carry){
        int sum=(x-'0')+(y-'0')+(carry?1:0);
        carry=(sum>=2);
        return (sum%2)+'0';
    }

    string addBinary(string a, string b) {
        int i=a.size()-1,j=b.size()-1;
        bool carry=false;
        string ans="";
        
        while(i>=0 or j>=0){
            char x=(i>=0?a[i]:'0');
            char y=(j>=0?b[j]:'0');
            
            ans+=logic(x,y,carry);
            i--;j--;
        }
        
        if(carry) ans+='1';
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
