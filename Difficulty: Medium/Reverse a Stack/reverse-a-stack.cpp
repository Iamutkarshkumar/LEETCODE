class Solution {
  public:
    void insertAtBottom(stack<int> &st,int topEle){
        //base case
        if(st.empty()){
            st.push(topEle);
            return;
        }
        
        int x=st.top();
        st.pop();
        insertAtBottom(st,topEle);
        st.push(x);
    }
    void reverseStack(stack<int> &st) {
        //base case
        if(st.empty()) return;
        
        int topEle=st.top();
        st.pop();
        reverseStack(st);
        insertAtBottom(st,topEle);
    }
};