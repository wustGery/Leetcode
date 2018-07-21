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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        ListNode *pHead = new ListNode(-1);
        pHead->next = NULL;
        ListNode *ptr = pHead;
        while(l1&&l2)
        {
            int val_1 = l1->val;
            int val_2 = l2->val;
            if(val_1<val_2)  
            {
                ListNode *temp = l1;
                l1 = l1->next;
                temp->next = ptr->next;
                ptr->next = temp;
                ptr = temp;
            }
            else 
            {
                ListNode  *temp1 = l2;
                l2 = l2->next;
                temp1->next  = ptr->next;
                ptr->next = temp1;
                ptr = temp1;
            }
        }
        if(!l1) ptr->next = l2;
        else ptr->next = l1;
        return pHead->next;
    }
};
