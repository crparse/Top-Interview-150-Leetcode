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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || left == right) return head;
        
        ListNode* prev = nullptr;
        ListNode* tail = nullptr;
        ListNode* temp = nullptr;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        prev = dummy;

        for(int i = 0; i < left - 1; i++) prev = prev->next;
        tail = prev->next;
        for(int i = 0; i < right - left; i++) {
            temp = prev->next;
            prev->next = tail->next;
            tail->next = tail->next->next;
            prev->next->next = temp;
        }

        return dummy->next;
    }
};
