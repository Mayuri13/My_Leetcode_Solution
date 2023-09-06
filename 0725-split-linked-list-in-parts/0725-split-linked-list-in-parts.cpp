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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>ans;
        ListNode* curr = head;
        int n = 0;
        while(curr!=NULL){
            n++;
            curr = curr->next;
        }
        int fdiv = 0, cdiv = 0, m = 0;
        if(n<=k){
            fdiv = 1;
        }
        else if(n%k==0){
            fdiv = n/k;
        }
        else if(n%k!=0){
            double div = (double) n/k;
            fdiv = floor(div);
            m = n%k;
            cdiv = ceil(div);
        }
        
        //If cdiv exist and m>0
        ListNode* nex = head;
        while(m>0){
            ListNode* dummy = new ListNode(-1);
            curr = nex;
            dummy->next = curr;
            for(int i=1; i<cdiv; i++){
                curr = curr->next;
            }
            nex = curr->next;
            curr->next = NULL;
            ans.push_back(dummy->next);
            m--;
        }
        curr = nex;
        ListNode* dummy = new ListNode(-1);
        dummy->next = curr;
        int cnt = fdiv;
        while(curr!=NULL){
            cnt--;
            if(cnt==0){
                cnt = fdiv;
                nex = curr->next;
                curr->next = NULL;
                ans.push_back(dummy->next);
                dummy->next = nex;
                curr = nex;
                continue;
            }
            curr = curr->next;
        }
        while(ans.size()<k){
            ListNode* dummy = NULL;
            ans.push_back(dummy);
        }
        return ans;
    }
};