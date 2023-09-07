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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0), *curr = head;
        int n = 0;
        while(curr!=NULL){
            curr = curr->next;
            n++;
        }
        cout<<n;
        dummy->next = head;
        ListNode* prev = dummy;
        curr = head;
        prev->next = curr;
        int mul = n/k;
        while(mul>0){
            for(int i=1; i<k; i++){
                ListNode* nex = curr->next;
                curr->next = nex->next;
                nex->next = prev->next;
                prev->next = nex;
            }
            prev = curr;
            curr = curr->next;
            mul--;
        }
        return dummy->next;
    }
};