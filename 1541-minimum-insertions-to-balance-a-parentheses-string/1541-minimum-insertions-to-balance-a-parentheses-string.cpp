
class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int ans=0;
        int i=0,n=s.length();

        while(i<n){
            if(s[i]=='(') st.push('(');
            else{
                if(i+1<n and s[i+1]==')') i++;
                else ans++;

                if(!st.empty()) st.pop();
                else ans++;
            }
            i++;
        }

        return ans+2*st.size();
    }
};
