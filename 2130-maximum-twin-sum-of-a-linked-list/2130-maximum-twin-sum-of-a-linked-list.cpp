class Solution {
public:
    int pairSum(ListNode* head) {
        int n=0;
        ListNode* temp=head;
        while(temp){
            n++;
            temp=temp->next;
        }
        unordered_map<int,int> mp;
        int i=0;
        int ans=INT_MIN;
        temp=head;
        while(i<n){
            if(mp.count(n-i-1)) ans=max(ans,mp[n-i-1]+temp->val);
            else mp[i]=temp->val;
            temp=temp->next;
            i++;
        }
        return ans;
    }
};