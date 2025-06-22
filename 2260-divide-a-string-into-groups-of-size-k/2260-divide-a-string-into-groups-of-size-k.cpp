class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n=s.length();
        int rem=n%k;
        for(int i=0;i<n-rem;i+=k) ans.push_back(s.substr(i,k));
        if(rem!=0){
            string addon="";
            for(int i=n-rem;i<n;i++) addon+=s[i];
            int toaddfill=k-rem;
            while(toaddfill--) addon+=fill;
            ans.push_back(addon);
        }
        return ans;
    }
};