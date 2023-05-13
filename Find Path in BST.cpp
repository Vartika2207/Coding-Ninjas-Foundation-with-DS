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
//corrrct- app1
vector<int>* getPath_helper(BinaryTreeNode<int> *root , int data) {
	
    if(root==NULL) return NULL;
    if(root->data==data) {
        vector<int>*path=new vector<int>();
        path->push_back(root->data);
        return path;
    }
    vector<int>*leftPath=getPath_helper(root->left,data);
    if(leftPath!=NULL) {
        leftPath->push_back(root->data);
        return leftPath;
    }
    vector<int>*rightPath=getPath_helper(root->right,data);
    if(rightPath!=NULL) {
        rightPath->push_back(root->data);
        return rightPath;
    }
}


vector<int>* getPath(BinaryTreeNode<int> *root , int data) {
	return getPath_helper(root, data);
}