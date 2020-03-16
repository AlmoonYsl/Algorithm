/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int p = 0;
        ListNode* dummyHead = new ListNode(0);
        ListNode* cur = dummyHead;
        while(l1 != nullptr || l2 != nullptr || p != 0){
            if(l1 != nullptr){
                p += l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr){
                p += l2->val;
                l2 = l2->next;
            }
            cur->next = new ListNode(p % 10);
            cur = cur->next;
            p /= 10;
        }
    return dummyHead->next;
    }
};