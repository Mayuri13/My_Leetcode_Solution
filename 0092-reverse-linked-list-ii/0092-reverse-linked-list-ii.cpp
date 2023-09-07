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
    //Most optimised way of solving
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        
        //to get the node just before the left positioned node
        for(int i=0; i<left-1; i++){
            prev = prev->next;
        }
        
        ListNode* curr = prev->next;
        for(int i=0; i<right-left; i++){
            //prev and curr are intact and only the links are interchanged
            ListNode* nex = curr->next;
            curr->next = nex->next;
            nex->next = prev->next;
            prev->next = nex;
        }
        return dummy->next;
    }
};