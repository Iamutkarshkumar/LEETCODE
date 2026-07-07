class Solution {
public:
    char anti(char x){
        if(x==')') return '(';
        if(x=='}') return '{';
        if(x==']') return '[';
        return '0';
    }
    bool isValid(string s) {
        stack<char> st;
        for(auto ele: s){
            if(!st.empty() and anti(ele)==st.top()) st.pop();
            else st.push(ele);
        }
        return st.size()==0;
    }
};