/**
 * leetcode no.24
 * 
 */
ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    auto* dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode* next = head->next;
    dummyHead->next = next;
    head->next = next->next;
    next->next = head;
    while(head->next != nullptr){
        ListNode* pre;
        ListNode* cur;
        ListNode* post;
        pre = head;
        if (head->next != nullptr){
            cur = head->next;
        } else{
            return dummyHead->next;
        }
        if (cur->next != nullptr){
            post = cur->next;
        } else{
            return dummyHead->next;
        }
        cur->next = post->next;
        post->next = cur;
        pre->next = post;
        head = cur;
    }
    return dummyHead->next;
}