/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

#include<iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode *parent, ListNode *node) 
{
	if(node->next==NULL) {
		node->next = parent;
		return NULL;
	}
	reverseList(node, node->next);
	node->next = parent;
	return NULL;
}

void playList(ListNode *node)
{
	while(node) {
		std::cout<<node->val<<" ";
		node = node->next;
	}
	std::cout<<std::endl;
}

int main(int agrc, char** agrv)
{
	std::cout<<"Hello!"<<std::endl;
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);
	ListNode* n5 = new ListNode(5);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	playList(n1);
	n1->next = reverseList(n1, n2);
	playList(n5);
	return 0;
}
