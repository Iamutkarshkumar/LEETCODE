class Solution {
public:
    string maxcheck(string a,string b){
        if(a[0]>b[0]) return a;
        else return b;
    }
    string largestGoodInteger(string num) {
        int n=num.length();
        int x=INT_MIN;
        string ans="";
        for(int i=2;i<n;i++){
            if(num[i]==num[i-1] and num[i-1]==num[i-2]){
                ans=maxcheck(num.substr(i-2,3) , ans);
            }
        }
        return ans;
    }
};