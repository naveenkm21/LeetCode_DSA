class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if (!head) return nullptr;

        ListNode* prev = nullptr;
        ListNode* cur  = head;
        while (cur) {
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        int maxSoFar = prev->val;
        ListNode* newHead = prev;     
        ListNode* tail    = prev;     
        prev = prev->next;

        while (prev) {
            if (prev->val >= maxSoFar) {
                maxSoFar = prev->val;
                tail->next = prev;    
                tail = prev;
            }
            prev = prev->next;
        }
        tail->next = nullptr;        

        ListNode* p = newHead;
        prev = nullptr;
        while (p) {
            ListNode* nxt = p->next;
            p->next = prev;
            prev = p;
            p = nxt;
        }

        return prev;                  
    }
};
