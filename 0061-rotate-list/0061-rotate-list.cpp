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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0) return head;
        //Step1: finding length of the list and also the end pointer

        ListNode* ptr = head, *end = head;
        int n = 0;
        while(ptr != NULL){
            end = ptr;    
            ptr = ptr->next;
            n++;
        }

        //Step2: move ptr to n-kth node.

        k = k % n;
        if(k == 0) return head;
        
        ptr = head;

        for(int i=0; i<(n-k-1); i++){
            ptr = ptr->next;
        }

        //Step3: changing the links

        ListNode* nex = ptr->next;
        ptr->next = NULL;
        end->next = head;

        return nex;
        
    }
};