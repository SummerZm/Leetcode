/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) return head;  // []
        return _removeNthFromEnd(head, n);
    }
    
    ListNode* _removeNthFromEnd(ListNode* head, int& n) {
		// 递归退出条件
        if (head->next == NULL) {   // [1]
            if (--n==0) {   
                delete head;
                head = NULL;
            }
            return head;
        }
		// 递归到链表最底层
        head->next = _removeNthFromEnd(head->next, n);
		// 进行回溯处理
        if(--n==0) {    // [1, 2] or [1, 2, 3]
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }
        return head;
    }
};
// @lc code=end

