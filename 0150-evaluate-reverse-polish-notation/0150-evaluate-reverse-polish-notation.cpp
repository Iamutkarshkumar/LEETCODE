class Solution {
public:
    int evalRPN(vector<string>& t) {
        int n=t.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            if(t[i]=="+"){
                int sec=st.top();st.pop();
                int fir=st.top();st.pop();
                st.push(fir+sec);
                
            }
            else if(t[i]=="-"){
                int sec=st.top();st.pop();
                int fir=st.top();st.pop();
                st.push(fir-sec);
                
            }
            else if(t[i]=="*"){
                int sec=st.top();st.pop();
                int fir=st.top();st.pop();
                st.push(fir*sec);
                
            }
            else if(t[i]=="/"){
                int sec=st.top();st.pop();
                int fir=st.top();st.pop();
                st.push(fir/sec);
                
            }
            else st.push(stoi(t[i]));
        }
        return st.top();
    }
};