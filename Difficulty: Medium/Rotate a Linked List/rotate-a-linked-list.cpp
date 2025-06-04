class Solution {
  public:
    Node* rotate(Node* head, int k) {
        if(!head || !head->next || k==0) return head;

        vector<Node*> v;
        Node* temp = head;
        while(temp){
            v.push_back(temp);
            temp = temp->next;
        }

        int n = v.size();
        k = k % n; // In case k > n
        if(k == 0) return head;


        reverse(v.begin(), v.begin() + k);
        reverse(v.begin() + k, v.end());
        reverse(v.begin(), v.end());


        for(int i = 0; i < n - 1; i++) {
            v[i]->next = v[i + 1];
        }
        v[n - 1]->next = NULL;
        return v[0];
    }
};
