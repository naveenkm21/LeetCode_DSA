class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode beforeHead(0), afterHead(0); // dummy nodes
        ListNode *before = &beforeHead, *after = &afterHead;

        while (head) {
            if (head->val < x) {
                before->next = head;
                before = before->next;
            } else {
                after->next = head;
                after = after->next;
            }
            head = head->next;
        }

        after->next = nullptr; // important to end list
        before->next = afterHead.next;

        return beforeHead.next;
    }
};
