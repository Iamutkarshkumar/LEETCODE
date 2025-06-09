/*

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution {
  public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
        if(!head or !head->next) return false;
        Node* s=head;
        Node* f=head;
        while(f and f->next){
            s=s->next;
            f=f->next->next;
            if(s==f) return true;
        }
        return false;
    }
};