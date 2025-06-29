class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        while (head) {
            // Check for duplicates
            if (head->next && head->val == head->next->val) {
                // Skip nodes with same value
                while (head->next && head->val == head->next->val) {
                    head = head->next;
                }
                prev->next = head->next; // unlink all duplicates
            } else {
                prev = prev->next;
            }
            head = head->next;
        }

        return dummy.next;
    }
};
