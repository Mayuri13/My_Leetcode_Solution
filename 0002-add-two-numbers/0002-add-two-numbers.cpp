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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *temp1=NULL;
    int sum=0, c=0, x=0;
    while (l1!=NULL && l2!=NULL)
    {
        sum=l1->val+l2->val+c;
        if(sum>9){
            c=sum/10;
            x=sum%10;
        }
        else{
            c=0;
            x=sum;
        }
        
        ListNode *temp2=new ListNode(x);
        temp2->next=temp1;
        temp1=temp2;
        l1=l1->next;
        l2=l2->next;
    }
        
    while (l1!=NULL)
    {
        sum=l1->val+c;
        if(sum>9){
            c=sum/10;
            x=sum%10;
        }
        else{
            c=0;
            x=sum;
        }
        
        ListNode *temp2=new ListNode(x);
        temp2->next=temp1;
        temp1=temp2;
        l1=l1->next;
    }
    while (l2!=NULL)
    {
        sum=l2->val+c;
        if(sum>9){
            c=sum/10;
            x=sum%10;
        }
        else{
            c=0;
            x=sum;
        }
        
        ListNode *temp2=new ListNode(x);
        temp2->next=temp1;
        temp1=temp2;
        l2=l2->next;
    }
    
    if(c!=0){
       
        ListNode *temp2=new ListNode(c);
        temp2->next=temp1;
        temp1=temp2;
    }
        
    ListNode *prev=NULL;
    ListNode *curr=temp1;
    while (curr!=NULL)
    {
        ListNode *next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    
    return prev;
    }
};