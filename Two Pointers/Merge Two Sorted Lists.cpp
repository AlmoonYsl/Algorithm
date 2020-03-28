/**
 * leetcode no.21
 * 
 */
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr && l2 == nullptr) return nullptr;
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;
    auto* dummyHead = new ListNode(0);
    ListNode* t = dummyHead;
    ListNode* p = l1;
    ListNode* q = l2;
    while (p != nullptr && q != nullptr){
        if (p->val < q->val){
            t->next = p;
            p = p->next;
        } else{
            t->next = q;
            q = q->next;
        }
        t = t->next;
    }
    if (p == nullptr){
        t->next = q;
    }
    if (q == nullptr){
        t->next = p;
    }
    return dummyHead->next;
}