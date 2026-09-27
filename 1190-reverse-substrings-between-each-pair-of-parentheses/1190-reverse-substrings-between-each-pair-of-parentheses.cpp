class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string temp;

        for(char c : s){
            if(c=='('){
                st.push(temp);
                temp="";
            }
            else if(c==')'){
                reverse(temp.begin(),temp.end());
                temp=st.top()+temp;
                st.pop();
            }
            else{
                temp.push_back(c);
            }
        }
        return temp;
    }
};