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
    ListNode* partition(ListNode* head, int x) {
        //create Two Dummy Nodes 
        ListNode beforeHead(-1);
        ListNode* before = &beforeHead;

        ListNode afterHead(-1);
        ListNode* after = &afterHead;

        //we'll iterate the LL and put less than X element in before 
        // where as put greater than element in beefore    
        while(head != NULL){
            if(head->val < x){
                before->next=head;
                before=before->next;
            }else{
                after->next = head;
                after=after->next;
            }
            head=head->next;
        }
        //now combine both before & after to get desired output & make last node
        // to NULL
        after->next=NULL;
        before->next =afterHead.next;
        return beforeHead.next;
    }
};