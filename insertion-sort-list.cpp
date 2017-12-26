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
    ListNode *insertionSortList(ListNode *head) {
		
		if(head == NULL || head->next ==NULL )return head;
		ListNode dummy(0);
		ListNode * curr = head;
		
		while(curr)
		{
			ListNode *next = curr->next;
			ListNode *node = &dummy;
			
			while(node->next&&((node->next->val) < (curr->val)))
			{
				node = node->next;
			}
			
			curr->next = node->next;
			node->next = curr;
			curr = next;
		}
		return dummy.next;
    }
};