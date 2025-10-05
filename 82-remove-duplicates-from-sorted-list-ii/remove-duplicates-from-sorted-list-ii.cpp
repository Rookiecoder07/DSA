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
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* head1 = new ListNode(-1);  
        ListNode* temp1 = head1;
        temp1->next = head;
        ListNode* curr = head;

        while (curr != nullptr && curr->next != nullptr) {
            if (curr->val == curr->next->val) {
                while (curr->next != nullptr && curr->val == curr->next->val) {
                    curr = curr->next;
                }
                temp1->next = curr->next;  // Skip duplicates
            } else {
                temp1 = temp1->next;  
            }
            curr = curr->next;  
        }

        return head1->next;
    }
};