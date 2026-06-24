
class Solution {
public:
    Node* reverse(Node* head){
        Node* prev = NULL;
        while(head){
            Node* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }

    bool isPalindrome(Node* head) {

        Node* slow = head;
        Node* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* second = reverse(slow);
        while(second){
            if(head->data != second->data){
                return false;
            }
            head = head->next;
            second = second->next;
        }
        return true;
    }
};