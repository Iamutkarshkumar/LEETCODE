class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st; // storing idx
        int n=s.length();
        for(int i=0;i<n;i++){
            if(!st.empty() and s[st.top()]=='(' and s[i]==')') st.pop();
            else if(s[i]==')' or s[i]=='(') st.push(i);
        }
        unordered_set<int> toSkip;
        while(!st.empty()){
            // cout<<st.top()<<" ";
            toSkip.insert(st.top());
            st.pop();
        }
        string ans;
        for(int i=0;i<n;i++){
            if(toSkip.count(i)) continue;
            ans.push_back(s[i]);
        }
        return ans;
    }
};