class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(i!=0 and st.size()!=0 and s[i]==')' and st.top()=='(') st.pop();
            else st.push(s[i]);
        }
        return st.size();
    }
};