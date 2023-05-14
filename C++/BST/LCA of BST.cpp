
BinaryTreeNode<int>* helper(BinaryTreeNode<int>*root, int a, int b){
   
    if(root == NULL || root->data==a || root->data==b) return root;

    if(a < root->data && b<root->data)
        return helper(root->left,a,b);
        
    else if(a>root->data&&b>root->data)
        return helper(root->right,a,b);

    // rec call
    BinaryTreeNode<int>* leftLCA=helper(root->left,a,b);
    BinaryTreeNode<int>* rightLCA=helper(root->left,a,b);
    
   
    if(leftLCA && rightLCA) return root;
    else if(leftLCA) return leftLCA;
    else return rightLCA;
}



int getLCA(BinaryTreeNode<int>* root , int val1 , int val2){
        if(!root) return -1;
        BinaryTreeNode<int>*ans=helper(root,val1,val2);
        if(ans!=NULL) return ans->data;
        return -1;
}



