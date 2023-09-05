/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return NULL;
        Node* dummy = new Node(100000);
        Node* curr = new Node(head->val);
        dummy->next = curr;
        map<Node*,Node*>mp;
        mp[head] = curr;
        
        while(head!=NULL){
            //storing all the nodes in a set
            if(mp.find(head->next)!=mp.end()){
                curr->next = mp[head->next];
            }
            else if(head->next==NULL){
                curr->next = NULL;
            }
            else{
                mp[head->next] = new Node(head->next->val);
                curr->next = mp[head->next];
            }
            if(mp.find(head->random)!=mp.end()){
                curr->random = mp[head->random];
            }
            else if(head->random==NULL){
                curr->random = NULL;
            }
            else{
                mp[head->random] = new Node(head->random->val);
                curr->random = mp[head->random];
            }
            head = head->next;
            curr = curr->next;
        }
        return dummy->next;
    }
};