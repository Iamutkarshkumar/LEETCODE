class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            while(!st.empty() and st.top()-'0'>num[i]-'0' and k>0){
                st.pop();
                k--;
            } 
            st.push(num[i]);
        }
        while(k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        
        if(st.empty()) return "0";
        
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(begin(ans), end(ans));
        
        int i = 0;
        while(i < ans.size() && ans[i] == '0') i++;
        if(i == ans.size()) return "0";
        return ans.substr(i);
    }
};
