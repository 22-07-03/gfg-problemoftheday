//AMAZON
void convert(Node *head, TreeNode *&root) {
    if(head==nullptr){ return ;}
    vector<int>vec;
    Node* vec_temp=head;
    while(vec_temp){
        vec.push_back(vec_temp->data); vec_temp= vec_temp->next;}
    
    if(root==nullptr){ root= new TreeNode(vec[0]); }
    queue<TreeNode*>q;
    q.push(root); int i =1;

    while(!q.empty() && i<vec.size()){
        TreeNode* left_node = new TreeNode(vec[i]);
        TreeNode* parent = q.front(); q.pop();
        if(parent->left==nullptr){
            parent->left = left_node; q.push(parent->left);
        }
        i++; 
        if(i==vec.size()){break;}
         TreeNode* right_node = new TreeNode(vec[i]);
         if(parent->right==nullptr){
            parent->right = right_node; q.push(parent->right);
        }
       i++; 
       
    }
 
