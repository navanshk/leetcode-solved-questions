/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode* start=new ListNode();
        start->next=head;
         ListNode* f=start;
         ListNode* s=start;
        for(int i=1;i<=n;i++)
            s=s->next;
        while( s->next!=NULL)
        {
             s=s->next;
             f=f->next;
        }
        f->next=f->next->next;
        return start->next;
    }
};