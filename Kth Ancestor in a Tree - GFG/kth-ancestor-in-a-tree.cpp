//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}
int kthAncestor(Node *root, int k, int node);

int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        int k , node;
        scanf("%d ",&k);
        scanf("%d ",&node);
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		cout<<kthAncestor(root,k,node)<<endl;
    }
    return 0;
}

// } Driver Code Ends


//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function
int height = 0;
void getHeight(Node *root, int node, int h){
    if(root==NULL)
        return;
    if(root->data == node){
        height = h;
        return;
    }
    getHeight(root->left, node, h+1);
    getHeight(root->right, node, h+1);
}
void getNode(Node *root, int level, vector<Node*>&v){
    if(root==NULL)
        return;
    if(level==0){
        v.push_back(root);
        return;
    }
    getNode(root->left, level-1, v);
    getNode(root->right, level-1, v);
}

bool dfs(Node *root, int node){
    if(root==NULL)
        return false;
    if(root->data==node)
        return true;
    return dfs(root->left, node) || dfs(root->right,node);
}

int kthAncestor(Node *root, int k, int node)
{
    //getting height of the node
    getHeight(root, node, 0);
    int level = height-k, ans=0;
    if(level<0)
        return -1;
    else if(level==0)
        return root->data;
    else{
        vector<Node*>v;
        getNode(root, level, v);
        for(int i=0; i<v.size(); i++){
            if(dfs(v[i],node))
                return v[i]->data;
        }
    }
    return 0;
}
