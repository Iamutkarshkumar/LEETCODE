/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution{
    Node* rev(Node* h){
        Node *p=NULL,*c=h,*n;
        while(c){
            n=c->next;
            c->next=p;
            p=c;
            c=n;
        }
        return p;
    }
public:
    Node* addTwoLists(Node* num1, Node* num2){
        num1=rev(num1);
        num2=rev(num2);
        Node *res=NULL,*tail=NULL;
        int carry=0;
        while(num1||num2||carry){
            int s=(num1?num1->data:0)+(num2?num2->data:0)+carry;
            carry=s/10;
            Node* t=new Node(s%10);
            if(!res) res=tail=t;
            else tail=tail->next=t;
            if(num1) num1=num1->next;
            if(num2) num2=num2->next;
        }
        res=rev(res);
        while(res->data==0 && res->next) res=res->next;
        return res;
    }
};
