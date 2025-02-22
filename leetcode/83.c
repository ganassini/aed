/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *p = head, *q = NULL;

    while ( p != NULL ) {
        if ( p->next == NULL )
            return head;
        
        q = p->next;

        while ( q != NULL && p->val == q->val )
            q = q->next;
        
        p->next = q;
        p = q;
    }

    return head;
}
