
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s;
        for(auto ele: nums) s.insert(ele);
        ListNode* temp = head;
        ListNode* prev = NULL; // To track the previous node
        while (temp) {
            if (s.find(temp->val) != s.end()) {
                // Remove the current node
                if (prev!=NULL) prev->next = temp->next;
                else head = temp->next; // If we're removing the head node
            } 
            else prev = temp;
            temp = temp->next; // Move to the next node
        }
        return head; // Return the updated head
    }
};