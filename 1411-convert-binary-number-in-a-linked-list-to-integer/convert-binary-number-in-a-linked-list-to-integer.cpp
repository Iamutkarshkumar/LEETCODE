/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int answer=0;
        ListNode* temp=head;
        while(temp){
            answer<<=1;
            answer=answer|temp->val;
            temp=temp->next;
        }
        return answer;
    }
};