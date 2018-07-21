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
    ListNode* swapPairs(ListNode* head) 
    {
        ListNode *p,*q,*r;
        if(head==NULL||head->next==NULL) return head;
        p = head;
        q = p->next;
        p->next = q->next;
        q->next = p;
        head = q;
        r = p;
        p = p->next;
        while(p)
        {
            q = p->next;
            if(!q) 
            {
                r->next = p;
                break;
            }
            p->next = q->next;
            q->next = p;
            r->next = q;
            r = p;
            p = p->next;
        }
        return head;
    }
};
