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
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

	if (l1 == NULL)return l2;
	if (l2 == NULL)return l1;
	int c = 0;
	ListNode* head = new ListNode(0);
	ListNode* pre = head;

	while (l1 || l2 || c)
	{
		int sum = 0;
		if (l1 != NULL)
		{
			sum += l1->val;
			l1 = l1->next;
		}
		if (l2 != NULL)
		{
			sum += l2->val;
			l2 = l2->next;
		}
		sum += c;
		c = sum / 10;
		ListNode* p = new ListNode(sum % 10);
		pre->next = p;
		pre = pre->next;
	}
	return head->next;
}
};