/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        if (!head || k <= 1) 
            return head;
        
        // 1) collect pointers to all nodes
        vector<Node*> nodes;
        for (Node* p = head; p; p = p->next)
            nodes.push_back(p);
        
        int n = nodes.size();
        // 2) reverse each chunk of size k, even the last partial chunk
        for (int start = 0; start < n; start += k) {
            int end = min(start + k, n);
            reverse(nodes.begin() + start, nodes.begin() + end);
        }
        
        // 3) relink in the new order
        for (int i = 0; i + 1 < n; i++)
            nodes[i]->next = nodes[i + 1];
        nodes[n - 1]->next = nullptr;
        
        // 4) new head is the first element in our vector
        return nodes[0];
    }
};