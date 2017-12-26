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
    ListNode *sortList(ListNode *head) {
    
		if((!head)||(!head->next))
			return head;
		ListNode * p = head, * q = head->next;
		
		while(q&&q->next)
		{
			p = p->next;
			q = q->next->next;
		}
		
		ListNode* right = sortList(p->next);
		p->next = NULL;
		ListNode* left = sortList(head);
		return merge(left, right);
    }
	
	
	ListNode * merge(ListNode* L1, ListNode* L2)
	{
		if(L1 == NULL)
			return L2;
		if(L2 == NULL)
			return L1;
		
		ListNode d(0);
		ListNode * p = &d;
		
		while(L1&&L2)
		{
			if(L1->val < L2->val)
			{
				p->next = L1;
				L1 = L1->next;
			}
			else
			{
				p->next = L2;
				L2 = L2->next;
			}
			p = p->next;
		}
		if(L1)
			p->next = L1;
		if(L2)
			p->next = L2;
		return d.next;	
	}
	
};