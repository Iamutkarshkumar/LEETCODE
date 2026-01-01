/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        unordered_set<Node*> s;
        Node* temp=head1;
        while(temp){
            s.insert(temp);
            temp=temp->next;
        }
        
        // Node* ans=NULL;
        temp=head2;
        while(temp){
            if(s.count(temp)) return temp;
            temp=temp->next;
        }
        return NULL;
    }
};