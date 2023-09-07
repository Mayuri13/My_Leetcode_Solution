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
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        if(l==r) return head;
        int i = 1;
        ListNode* curr = head, *lprev;
        while(curr!=NULL){
            //when left is 1st position
            if(l==1){
                ListNode* prev = NULL;
                ListNode* nex;
                
                while(i<=r){
                    nex = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = nex;
                    i++;
                }
                head = prev;
                while(prev->next!=NULL){
                    prev = prev->next;
                }
                prev->next = nex;
                return head;
            }
            //when left is other than 1st position
            if(i==l-1){
                lprev = curr;
                ListNode* prev = NULL;
                ListNode* nex;
                curr = curr->next;
                i++;
                while(i<=r){
                    nex = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = nex;
                    i++;
                }
                lprev->next = prev;
                while(prev->next!=NULL){
                    prev = prev->next;
                }
                prev->next = nex;
                break;
            }
            curr = curr->next;
            i++;
        }
        return head;
    }
};