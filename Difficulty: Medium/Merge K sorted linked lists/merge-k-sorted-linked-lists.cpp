/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/
struct compare {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data; 
    }
};
class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        priority_queue<Node*,vector<Node*>, compare> pq;
        for (auto node : arr) {
            if (node) pq.push(node);
        }
        
        Node* dummy = new Node(-1);
        Node* tail = dummy;
        
        while (!pq.empty()) {
            Node* curr = pq.top();
            pq.pop();
            tail->next = curr;
            tail = tail->next;
            
            if (curr->next) {
                pq.push(curr->next);
            }
        }
        Node* result = dummy->next;
        delete dummy;
        return result;
        
    }
};