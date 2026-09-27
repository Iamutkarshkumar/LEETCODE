// class Solution {
// public:
//     string reverseParentheses(string s) {
//         stack<string> st;
//         string temp;

//         for(char c : s){
//             if(c=='('){
//                 st.push(temp);
//                 temp="";
//             }
//             else if(c==')'){
//                 reverse(temp.begin(),temp.end());
//                 temp=st.top()+temp;
//                 st.pop();
//             }
//             else{
//                 temp.push_back(c);
//             }
//         }
//         return temp;
//     }
// };

class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string temp;
        int n=s.length();
        int i=0;

        while(i<n){
            if(s[i]=='('){
                st.push(temp);
                temp="";
                i++;
            }
            else if(s[i]==')'){
                reverse(temp.begin(),temp.end());
                temp=st.top()+temp;
                st.pop();
                i++;
            }
            else{
                temp.push_back(s[i]);
                i++;
            }
        }

        return temp;
    }
};