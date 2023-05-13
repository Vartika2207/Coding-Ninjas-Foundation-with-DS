/**********************************************************

	Following are the Binary Tree Node class structure and the 
	Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

	template <typename T>
 	class Node{
    	public:
    	T data;
    	Node<T> *next;
    
    	Node(T data) {
        	this->data = data;
        	this->next = NULL;
    	}
 	};

***********************************************************/

void util(BinaryTreeNode<int>* root,Node<int>* &head,Node<int>* &lastVisitedNode){
    if(!root){
        return;
    }
    util(root->left,head,lastVisitedNode);
    Node<int>* n=new Node<int>(root->data);
    if((head)==NULL){
        head=n;
    }
    else{
        (lastVisitedNode)->next=n;
    }
    lastVisitedNode=n;
    util(root->right,head,lastVisitedNode);
    
}

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
    
    
    // Node<int>* head = NULL;
    // Node<int>* l =NULL;
    // util(root, head, l);
    // return head;
    
	if(!root)
        return nullptr;
    
    if(!root->left && !root->right){
        Node<int> *node = new Node<int>(root->data);
        return node;
    }
    
    Node<int> *left = constructLinkedList(root->left);
    Node<int> *right = constructLinkedList(root->right);

    Node<int>* root_node = new Node<int>(root->data);
    
    //if left child tree
    if(left) {
        //finding tail of left list
        Node<int>* left_tail = left;
        while(left_tail && left_tail->next)
            left_tail = left_tail->next;
        
        left_tail->next = root_node;
    }
    root_node->next = right;

    return left?left:root_node;
}
