/**
 * leetcode no.24
 * 
 */
ListNode* swapPairs(ListNode* head) {
    auto *dummyHead = new ListNode(0);
    ListNode* h = dummyHead;
    ListNode* p;
    ListNode* q;
    ListNode* t;
    ListNode* temp;
    if (head == nullptr || head->next == nullptr) return head;
    p = head;
    q = head->next;
    t = q->next;
    if (t == nullptr){
        q->next = p;
        p->next = t;
        h->next = q;
    }
    while (t != nullptr) {
        q->next = p;
        p->next = t;
        h->next = q;
        if (t->next == nullptr) {
            break;
        } else if (t->next->next == nullptr){
            temp = p;
            p = q->next->next;
            q = temp->next->next;
            h = h->next->next;
            q->next = p;
            p->next = nullptr;
            h->next = q;
            break;
        } else{
            temp = p;
            p = q->next->next;
            q = temp->next->next;
            h = h->next->next;
            t = t->next->next;
        }
    }
    return dummyHead->next;
}