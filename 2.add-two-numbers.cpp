/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int flag=0, total=0, v1=0, v2=0;
        ListNode *head=NULL, *node=NULL, *result=NULL;
        //while((l1 && l2))  -- error
        //while((l1 && l2) || flag) 
        while(l1 || l2 || flag) 
        {
            if(l1) {
                v1 = l1->val; 
                l1 = l1->next;
            }
            else v1 = 0;

            if(l2) {
                v2 = l2->val; 
                l2 = l2->next;
            }
            else v2 = 0;

            total = v1 + v2 + flag;
            if(total <= 9) {
                flag = 0; // miss error
            }
            else {
                total -= 10;
                flag = 1;
            }

            node = new ListNode(total);
            if(head) node->next = head;
            head = node;
            //l1 = l1->next; -- error
            //l2 = l2->next;
        }
        result = reverseList(head);
        return result;
    }

	ListNode* reverseList(ListNode* head) {
		ListNode* tail = head;
		if ( !head || !head->next) return head;
		while ( tail->next ) tail = tail->next;
		head->next = reverseList(head, head->next);
		return tail;
	}

    ListNode* _reverseList(ListNode *parent, ListNode *node) 
    {
        if(node->next==NULL) {
            node->next = parent;
            return NULL;
        }
        reverseList(node, node->next);
        node->next = parent;
        return NULL;
    }
};
// @lc code=end

