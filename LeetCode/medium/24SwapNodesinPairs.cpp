/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
基础, 两根指针交换,移动
*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *p = head;
        ListNode *q = head->next;
        head = q;
        ListNode *pre = NULL;
        while(p && q) {
            p->next = q->next;
            q->next = p;
            if (pre) {
                pre->next = q;
            }
            pre = p;
            p = p->next;
            if (p) {
                q = p->next;
            }
        }
        return head;
    }
};
