/*
  Clone a linked list with next and random pointers in O(N) time and O(1) auxiliary space.
  Approach:
  1. Interleave cloned nodes between original nodes.
  2. Assign random pointers for cloned nodes.
  3. Detach cloned list from original list.
*/
class Solution{
 public:
  Node* cloneLinkedList(Node* head){
    if(!head) return NULL;
    
    Node* cur=head;
    while(cur){
      Node* nn=new Node(cur->data);
      nn->next=cur->next;
      cur->next=nn;
      cur=nn->next;
    }

    cur=head;
    while(cur){
      if(cur->random)
        cur->next->random=cur->random->next;
      cur=cur->next->next;
    }

    Node* dummy=new Node(0),*tail=dummy;
    cur=head;
    while(cur){
      tail->next=cur->next;
      tail=tail->next;
      cur->next=tail->next;
      cur=cur->next;
    }
    return dummy->next;
  }
};
