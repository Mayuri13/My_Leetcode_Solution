/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        queue<Node*>q;
        map<Node*, Node*>mp;    //map for storing new nodes
        q.push(node);

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            
            vector<Node*>tmp;

            //Iterating through the neighbor nodes
            for(auto it:curr->neighbors){
                int data = it->val;
                if(mp.find(it)==mp.end()){
                    Node* newNode = new Node(data);
                    mp[it] = newNode;
                    q.push(it);
                }
                tmp.push_back(mp[it]);
            }
            if(mp.find(curr)==mp.end()){
                Node* newNode = new Node(curr->val);
                mp[curr] = newNode;
            }
            mp[curr]->neighbors = tmp;
        }
        for(auto it:mp){
            cout<<it.second->val;
        }
        return mp[node];
    }
};