class Solution {
  public:
     void traversal(Node* root, vector<Node*>&inorder){
         if(root==nullptr){return;}
         if(root->left){
             traversal(root->left,inorder);
         }
         inorder.push_back(root);
         if(root->right){
             traversal(root->right,inorder);
         }
     }
    void populateNext(Node *root) {
        if(!root){ return;}
               vector<Node*>inorder;
                traversal(root,inorder);
             for(int i =0;i<inorder.size()-1;i++){
                 inorder[i]->next = inorder[i+1];
             }
             
               
    }
};
