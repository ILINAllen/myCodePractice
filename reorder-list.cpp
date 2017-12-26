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
    void reorderList(ListNode *head) {
		if(!head||!head->next||!head->next->next)return ;
		
		
		ListNode *fast = head, *slow = head;
		while(fast&&fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
	
		ListNode *rear = slow->next;
		slow->next = NULL;
		ListNode *p = NULL;
		
		while(rear)
		{
			ListNode *next = rear->next;
			rear->next = p;
			p = rear;
			rear = next;
		}
		
		ListNode * a = head;
		ListNode * q = p;

		while(a&&q)
		{
			ListNode *temp = a->next;
			ListNode *temp2 = q->next;
			a->next = q;
			q->next = temp;
			a = temp;
			q = temp2;	
			
			/*p = q->next;
			q->next = a->next;
			a->next = q;
			a = q->next;
			q = p;*/
			
			
		}
    }
};