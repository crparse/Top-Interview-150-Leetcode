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

 /*
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* num1, ListNode* num2) {
        ListNode* dummyHead = new ListNode(-1); 
        ListNode* current = dummyHead;
        ListNode* temp1 = num1;
        ListNode* temp2 = num2;
        int carry=0;
        while(temp1 != NULL || temp2 != NULL){
            int sum=carry;
            if(temp1) sum += temp1->val;
            if(temp2) sum +=temp2->val;
            ListNode *newNode = new ListNode(sum % 10); 
            carry = sum / 10;

            current->next = newNode;
            current=current->next;
            if(temp1) temp1 = temp1->next;
            if(temp2) temp2 = temp2->next;
        }
        if(carry){
            ListNode *newNode = new ListNode(carry);
        }
        return dummyHead->next;
    }
};
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;
        ListNode* p = l1;
        ListNode* q = l2;
        int carry = 0;
        
        while (p != nullptr || q != nullptr) {
            int x = (p != nullptr) ? p->val : 0;
            int y = (q != nullptr) ? q->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
            if (p != nullptr) p = p->next;
            if (q != nullptr) q = q->next;
        }
        
        if (carry > 0) {
            current->next = new ListNode(carry);
        }
        
        return dummyHead->next;
    }
};
