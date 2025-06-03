/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution {
  public:
    Node* reverseList(struct Node* head) {
        Node* a=NULL;
        while(head){
            Node* b=head->next; 
            head->next=a;
            a=head;
            head=b;
        }
        return a;
    }
};