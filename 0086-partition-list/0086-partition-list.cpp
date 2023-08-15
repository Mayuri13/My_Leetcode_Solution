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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL)
            return head;
        ListNode* dummy = new ListNode(-300), *curr = head, *st = head;
        dummy->next = curr;
        queue<ListNode*>q;
        while(st!=NULL && st->val < x){
            st = st->next;
        }
          
        while(curr!=NULL){
            if(curr->val < x){
                dummy->next = curr->next;
                q.push(curr);
            }
            else{
                dummy = dummy->next;
            }
            curr = curr->next;
        }
        ListNode* root = new ListNode(-300); 
        if(!q.empty()){
            root = q.front();
            q.pop();
        }
        curr = root;
        while(!q.empty()){
            curr->next = q.front();
            q.pop();
            curr = curr->next;
        }
        if(root->val!= -300){
            curr->next = st;
            return root;
        }
        return st;
    }
};