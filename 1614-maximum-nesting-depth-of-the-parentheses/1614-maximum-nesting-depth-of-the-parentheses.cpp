class Solution {
public:
    int maxDepth(string s) {
        int n=s.length();
        vector<int> leftBracket(n,0),rightBracket(n,0);

        if(s[0]=='(') leftBracket[0]=1;
        if(s[0]==')') rightBracket[0]=1;

        for(int i=1;i<n;i++){
            if(s[i]=='(') leftBracket[i]=leftBracket[i-1]+1;
            else leftBracket[i]=leftBracket[i-1];

            if(s[i]==')') rightBracket[i]=rightBracket[i-1]+1;
            else rightBracket[i]=rightBracket[i-1];
        }

        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,leftBracket[i]-rightBracket[i]);
        }

        return ans;
    }
};