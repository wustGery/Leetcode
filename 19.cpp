/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p,*p1;
        p1 = head;
        while(n--)  p1 = p1->next;
        if(!p1)  return head->next;
        p = head;
        while(p1->next)
        {
            p = p->next;
            p1 = p1->next;
        }
        p->next = p->next->next;
        return head;
    }
};
