/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* sortedMerge(Node* list1, Node* list2) {
        
        // code here
        
        if(list1 == NULL)
           return list2;
           
           
        if(list2 == NULL)
           return list1;
           
        if(list1->data <= list2->data){
            list1->next = sortedMerge(list1->next,list2);
            
            return list1;
        }
        list2->next = sortedMerge(list1,list2->next);
        return list2;
    }
};