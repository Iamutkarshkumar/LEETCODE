class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        int n=s.length();
        for(auto &x:s){
            if(!st.empty() and st.top()==x) st.pop();
            else st.push(x);
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());st.pop();
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};