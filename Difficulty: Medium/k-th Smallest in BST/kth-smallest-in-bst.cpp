class Solution {
  public:
    int kthSmallest(Node *root, int k) {
        stack<Node*> st;
        Node* cur = root;
        while(cur || !st.empty()){
            while(cur){
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top(); st.pop();
            if(--k == 0) return cur->data;
            cur = cur->right;
        }
        return -1;
    }
};
