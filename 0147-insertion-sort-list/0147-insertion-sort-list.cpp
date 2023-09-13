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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = head;
        while(curr != NULL){
            prev = head;
            
            int val = curr->val;
            while(prev->val < val){
                prev = prev->next;
            }
            
            int value = prev->val;
            int tmp = 0;
            prev->val = val;
            while(prev != curr){
                prev = prev->next;
                tmp = prev->val;
                prev->val = value;
                value = tmp;
            }
            curr = curr->next;
        }
        return head;
    }
};