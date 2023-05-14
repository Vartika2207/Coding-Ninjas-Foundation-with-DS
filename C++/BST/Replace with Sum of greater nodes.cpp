/**********************************************************

	Following is the Binary Tree Node class structure

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

***********************************************************/



void helper(BinaryTreeNode<int>*root, int *sum){
    if(root==NULL) return;
   
    helper(root->right, sum);
    *sum+=root->data;
    root->data=*sum;
    helper(root->left, sum);
    
}

void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
    int sum=0;
    helper(root,&sum); 
}

