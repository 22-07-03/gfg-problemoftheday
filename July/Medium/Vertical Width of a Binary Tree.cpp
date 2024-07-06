class Solution {
  public:
    // Function to find the vertical width of a Binary Tree.
    int verticalWidth(Node* root) {
           if(root==nullptr){return 0;}
           queue<pair<Node*,int>>q;
           set<int>distances;
           q.push({root,0});
           distances.insert(0);
           while(!q.empty()){
               auto temp = q.front(); q.pop();
               
               Node* parent = temp.first; int horizantal_distance = temp.second;
               
               if(parent->left){
                   q.push({parent->left,horizantal_distance-1});
                   distances.insert(horizantal_distance-1);
               }
               if(parent->right){
                   q.push({parent->right,horizantal_distance+1});
                   distances.insert(horizantal_distance+1);
               }
           }
           
           return distances.size();
    }
};
