/**
 * leetcode no.23
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

ListNode* mergeKLists(vector<ListNode*>& lists, int left, int right) {
    if (left == right) return lists[left];
    int len = right + left;
    int mid = len / 2;
    ListNode* l = mergeKLists(lists, left, mid);
    ListNode* r = mergeKLists(lists, mid + 1 , right);
    return mergeTwoLists(l, r);
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    int len = lists.size() - 1;
    if (lists.empty()) return nullptr;
    if (len == 0) return lists[0];
    int mid = len / 2;
    ListNode* l = mergeKLists(lists, 0, mid);
    ListNode* r = mergeKLists(lists, mid + 1 , len);
    return mergeTwoLists(l, r);
}