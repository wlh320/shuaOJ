/*Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.*/
/**
 *
 *  * Definition for singly-linked list.
 *
 *   * struct ListNode {
 *
 *    *     int val;
 *
 *     *     struct ListNode *next;
 *
 *      * };
 *
 *       */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *pa = l1, *pb = l2, *pc, *p;
    pc = (struct ListNode*)malloc(sizeof(struct ListNode));
    pc->val = 0;
    pc->next = NULL;
    p = pc;
    while (pa && pb)
    {
        if (pa->val <= pb->val)
        {
            pc->next = pa;
            pa = pa->next;
        }
        else
        {
            pc->next = pb;
            pb = pb->next;
        }
        pc = pc->next;
    }
    pc->next = pa ? pa : pb;
    return p->next;
}
