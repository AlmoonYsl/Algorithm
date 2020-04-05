/**
 * leetcode no.25
 * 
 */
ListNode* reverseKGroup(ListNode* head, int k) {
    if(!head || !head->next || k == 1){
        return head;
    }
    auto* first = new ListNode(0);
    first->next = head;
    ListNode* start = first, *end=first;
    int count = 0;
    while(end != nullptr){
        end = end->next;
        count++;
        if(!end  && count < k){
            break;
        }
        if(end && count == k){
            ListNode* p = end->next;
            ListNode* q = start->next;
            reverseListNode(start->next, end);
            start->next = end;
            q->next = p;
            start = q;
            end = q;
            count = 0;
        }
    }
    return first->next;
}