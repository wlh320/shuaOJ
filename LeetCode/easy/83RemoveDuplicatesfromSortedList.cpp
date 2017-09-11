/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.


*/

/* 两个指针同时移动 如果相等就删除后面的 */

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p = head;
        if (!p) return NULL;
        ListNode *q = head->next;
        while(q) {
            if (p->val == q->val) {
                p->next = q->next;
                delete q;
                q = p->next;
            } else {
                p = q;
                q = q->next;
            }
        }
        return head;
    }
};
