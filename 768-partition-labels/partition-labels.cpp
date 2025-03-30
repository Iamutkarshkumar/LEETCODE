class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> v(26,0);
        for(int i=0;i<s.length();i++) v[s[i]-'a']=i;

        vector<int> ans;
        int i=0,j=v[s[0]-'a'];
        while(i<s.length()){
            for(int k=i+1;k<=j;k++){
                int x=s[k]-'a';
                if(v[x]>j){
                    j=v[x];
                }
            }
            ans.push_back(j-i+1);
            i=j+1;
            if(i<s.length()) j=v[s[i]-'a'];
        }
        return ans;
    }
};