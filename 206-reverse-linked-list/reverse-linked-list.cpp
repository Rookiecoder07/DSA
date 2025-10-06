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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head; // Base case: empty list or single node
        }

        ListNode* reversedList = reverseList(head->next); // Reverse the rest
        head->next->next = head; // Adjust the next pointer
        head->next = nullptr;    // Set current node's next to null

        return reversedList; // Return the new head
    }
};
