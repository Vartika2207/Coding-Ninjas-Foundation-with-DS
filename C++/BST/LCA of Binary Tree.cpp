/**********************************************************
	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/
BinaryTreeNode<int>* helper(BinaryTreeNode<int>*root,int a,int b){
    if(root==NULL) return NULL;
    if(root->data==a || root->data==b) return root;
    BinaryTreeNode<int>* leftLCA=helper(root->left,a,b);
    BinaryTreeNode<int>*rightLCA=helper(root->right,a,b);
    
    if(leftLCA && rightLCA) return root;
    else if(leftLCA) return leftLCA;
    else return rightLCA;
}

int getLCA(BinaryTreeNode <int>* root , int a, int b) {
    if(!root) return -1;
    BinaryTreeNode<int>*ans=helper(root,a,b);
    if(ans!=NULL) return ans->data;
    else return -1; 
}

