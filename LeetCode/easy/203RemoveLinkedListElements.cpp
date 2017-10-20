/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
*/

/* 很基础 */

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
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head->val == val)
            head = head->next;
        if (!head) return NULL;
        ListNode *pre = head;
        ListNode *p = head->next;
        while(p) {
            if (p->val == val) {
                pre->next = p->next;
                delete p;
                p = pre->next;
            } else {
                pre = p;
                p = p->next;
            }
        }
        return head;
    }
};
