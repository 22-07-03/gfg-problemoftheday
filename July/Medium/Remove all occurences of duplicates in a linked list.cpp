//MICROSOFT
class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
            map<int,int>mp;
            Node*temp = head; vector<int>nondup;
            while(temp){
                mp[temp->data]++;
                temp= temp->next;
            }
            for(auto it : mp){
            if(it.second==1){ nondup.push_back(it.first);}
            }
            
            if(nondup.size()==0){ return nullptr ;}
            Node * new_head= new Node(nondup[0]);
            Node* new_temp = new_head;
            
            for(int i =1;i<nondup.size();i++){
                Node* new_node = new Node(nondup[i]);
                 new_temp->next = new_node;
                 new_temp= new_node;
            }
            
            return new_head;
    }
};
