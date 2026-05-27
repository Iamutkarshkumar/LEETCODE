class Solution {
public:
    int numberOfSpecialChars(string w) {
        int n=w.size();
        int ans=0;
        vector<int> low(26,-1),up(26,-1);
        for(int i=0;i<n;i++){
            if(w[i]-'a'>=0 and w[i]-'a'<26){
                low[w[i]-'a']=i;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(w[i]-'A'>=0 and w[i]-'A'<26){
                up[w[i]-'A']=i;
            }
        }
        for(int i=0;i<26;i++){
            if(low[i]!=-1 and up[i]!=-1 and up[i]>low[i]) ans++;
        }
        return ans;
    }
};