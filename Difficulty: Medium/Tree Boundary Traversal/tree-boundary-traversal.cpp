class Solution {
  public:
    void addLeft(Node* root, vector<int>& res){
        Node* cur = root->left;
        while(cur){
            if(cur->left || cur->right) res.push_back(cur->data);
            if(cur->left) cur = cur->left;
            else cur = cur->right;
        }
    }
    
    void addLeaves(Node* root, vector<int>& res){
        if(!root) return;
        if(!root->left && !root->right){
            res.push_back(root->data);
            return;
        }
        addLeaves(root->left, res);
        addLeaves(root->right, res);
    }
    
    void addRight(Node* root, vector<int>& res){
        vector<int> tmp;
        Node* cur = root->right;
        while(cur){
            if(cur->left || cur->right) tmp.push_back(cur->data);
            if(cur->right) cur = cur->right;
            else cur = cur->left;
        }
        for(int i = tmp.size() - 1; i >= 0; i--) 
            res.push_back(tmp[i]);
    }
    
    vector<int> boundaryTraversal(Node *root) {
        vector<int> res;
        if(!root) return res;
        res.push_back(root->data);
        addLeft(root, res);
        // collect leaves from children only, to avoid duplicating root when it's the only node
        addLeaves(root->left, res);
        addLeaves(root->right, res);
        addRight(root, res);
        return res;
    }
};
