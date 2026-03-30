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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(slow != NULL){
            bool isduplicate = 0;

            while(fast != NULL && fast->val == slow->val){
                isduplicate = 1;
                fast = fast->next;
            }
            if(isduplicate == 1){
                prev->next = fast;
            }else{
                prev = slow;
            }
            slow = fast;
            if(fast != NULL){
                fast = fast->next;
            }
        }
        return dummy->next;
    }
};