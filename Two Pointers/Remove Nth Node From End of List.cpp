/**
 * leetcode no.19
 * 
 */
ListNode* removeNthFromEnd(ListNode* head, int n) {
    auto *dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode* p = dummyHead;
    ListNode* q = dummyHead;
    for (int i = 0; i < n + 1; ++i) {
        if (p == nullptr) return dummyHead->next;
        p = p->next;
    }
    while(p != nullptr){
        p = p->next;
        q = q->next;
    }
    q->next = q->next->next;
    return dummyHead->next;
}
