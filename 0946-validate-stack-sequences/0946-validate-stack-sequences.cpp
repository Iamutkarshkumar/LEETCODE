class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int m=popped.size();
        stack<int> st;
        int j=0;
        for(int x: pushed){
            st.push(x);
            while(!st.empty() and j<m and st.top()==popped[j]){
                st.pop();
                j++;
            }
        }
        return st.empty();
    }
};