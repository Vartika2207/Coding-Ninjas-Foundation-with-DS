/*****************
Next larger

Given a generic tree and an integer n. Find and return the node with next larger element in the tree i.e. find a node with value just greater than n.
Note: Return NULL if no node is present with the value greater than n.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.  
The following line contains an integer, that denotes the value of n.
Output format :
The first and only line of output contains data of the node, whose data is just greater than n.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
18
Sample Output 1 :
20
Sample Input 2 :
10 3 20 30 40 2 40 50 0 0 0 0 
21
Sample Output 2:
30
****************/
/************************************************************
 
    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;
    
        TreeNode(T data) {
            this->data = data;
        }
    
        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/
#include<bits/stdc++.h>

TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {
    
    TreeNode<int>* nearest_max_node = NULL;
    int gap = INT_MAX;
    queue<TreeNode<int>*> pn;
    pn.push(root);
    
    while(!pn.empty()){
        TreeNode<int>* front = pn.front();
        pn.pop();
        
        if(front->data > x){
            int temp_gap = front->data - x;
            if(temp_gap < gap){
                gap = temp_gap;
                nearest_max_node = front;
            }
        }
        
        for(int i=0; i < front->children.size(); i++){
            pn.push(front->children[i]);
        }
    }
    return nearest_max_node;
    
}


TreeNode<int>* getNextLargerElement_(TreeNode<int>* root, int x) {
    if(!root) 
       return NULL;

    if(!root->children.size())
       return root->data > x ? root : NULL;

    TreeNode<int>* nextLargestNode = NULL;

    if(root->data > x)
       nextLargestNode = root;

    for(int i=0; i<root->children.size(); i++) {
        TreeNode<int>* node = getNextLargerElement(root->children[i],  x);
        if(nextLargestNode == NULL)
           nextLargestNode = node;
        else if(node && node->data < nextLargestNode->data)
           nextLargestNode = node;
    }
    return nextLargestNode;
}
