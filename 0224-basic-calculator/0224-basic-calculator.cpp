using ll=long long;
class Solution {
public:
    int calculate(string s) {
        ll n=s.length();
        stack<int> st;
        ll number=0;
        ll result=0;
        ll sign=1;
        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                number=(number*(ll)10)+(s[i]-'0');
            }
            else if(s[i]=='+'){
                result+=sign*number;
                number=0;
                sign=1;
            }
            else if(s[i]=='-'){
                result+=sign*number;
                number=0;
                sign=-1;
            }
            else if(s[i]=='('){
                st.push(result);
                st.push(sign);
                number=0;
                result=0;
                sign=1;
            }
            else if(s[i]==')'){
                result+=number*sign;
                number=0;
                int last_sign=st.top();st.pop();
                int last_result=st.top();st.pop();
                result*=last_sign;
                result+=last_result;
            }
        }
        result+=number*sign;
        return result;
    }
};