/* 2816: Double a Number Represented as a Linked List
You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.
Return the head of the linked list after doubling it.

Input: head = [1,8,9]
Output: [3,7,8]
Explanation: The figure above corresponds to the given linked list which represents the number 189. 
Hence, the returned linked list represents the number 189 * 2 = 378.

Input: head = [9,9,9]
Output: [1,9,9,8]
Explanation: The figure above corresponds to the given linked list which represents the number 999. 
Hence, the returned linked list reprersents the number 999 * 2 = 1998. */

#define NULL '\0'
struct ListNode {
      int val;
      ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        //reverse list
        ListNode *curr_node = head;
        ListNode *prev, *next;
        prev = next = NULL;

        while(curr_node != NULL){
            next = curr_node->next;
            curr_node->next = prev;
            prev = curr_node;
            curr_node = next;
        }
        curr_node = prev;
        
        //double
        int num = 0;
        int borrow = 0;
        while(curr_node != NULL){
            num = (curr_node->val * 2%10) + borrow;
            borrow = curr_node->val * 2 / 10;
            
            curr_node->val = num;
            if(curr_node->next == NULL){
                break;
            }
            curr_node = curr_node->next;
        }
        if(borrow != 0){
            curr_node->next = new ListNode(borrow);
        }
        
        //reverse list
        curr_node = prev;
        prev = next = NULL;

        while (curr_node != NULL) {
            next = curr_node->next;
            curr_node->next = prev;
            prev = curr_node;
            curr_node = next;
        }
        curr_node = prev;
        return curr_node;

    }
};


int main(){
    int x[] = {1,8,9};
    ListNode *input = new ListNode();
    ListNode *head = input;
    int n = 3;
    for(int i = 0;i<n;i++){
        input->val = x[i];
        if(i == n-1){
            break;
        }
        input->next = new ListNode();
        input = input->next;
    }
    input = head;
    Solution s;
    s.doubleIt(input);
    
}