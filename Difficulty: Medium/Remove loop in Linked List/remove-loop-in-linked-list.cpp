class Solution {
  public:
    void removeLoop(Node* head) {
        Node* temp = head;
        set<Node*> s;
        while (temp && temp->next) {
            if (s.count(temp->next)) {
                // next node is already visited => loop detected
                temp->next = NULL;
                break;
            }
            s.insert(temp);
            temp = temp->next;
        }
    }
};
