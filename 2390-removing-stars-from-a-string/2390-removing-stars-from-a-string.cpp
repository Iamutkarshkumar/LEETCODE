class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for(auto &ele : s){
            if(!st.empty() and ele=='*'){
                st.pop();
            }
            else st.push(ele);
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};