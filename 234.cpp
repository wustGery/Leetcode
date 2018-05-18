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
    bool isPalindrome(ListNode* head) 
    {
        if(head==NULL) return true;
        if(head->next==NULL) return true;  
        int cnt = 0;
        ListNode* pHead = head;
        ListNode *l,*q,*p,*pre;
        bool ok = true;
        while(pHead)
        {
            ++cnt;
            pHead = pHead->next;
        }
        if(cnt%2==1)
        {
            l  = head;
            int ite = cnt/2;
            while(ite)
            {
                pre = l;
                l = l->next;
                --ite;
            }
            pre->next = NULL;
            p = l->next;
            l->next = NULL;
            while(p)
            {
                q = p;
                p = p->next;;
                q->next = l->next;;
                l->next = q;
            }
            l = l->next;
            while(head)
            {
                int x = head->val;
                int y = l->val;
                if(x!=y)
                {
                    ok = false;
                    break;
                }
                head = head->next;
                l = l->next;
            }
            
        }
        else 
        {
            l = head;
            int ite = cnt/2-1;
            while(ite)
            {
                l = l->next;
                --ite;
            }
            ListNode* pnew = new ListNode(0);
            pnew->next = l->next;
            l->next = NULL;
            l = pnew;
            p = l->next;
            l->next = NULL;
            while(p)
            {
                q = p;
                p = p->next;;
                q->next = l->next;;
                l->next = q;
            }
            l = l->next;
            while(head)
            {
                int x = head->val;
                int y = l->val;
                if(x!=y)
                {
                    ok = false;
                    break;
                }
                head = head->next;
                l = l->next;
            }
        }
        return ok?true:false;
    }
};
