class Solution {
  public:
    bool compute(Node* head) {
        Node*temp = head; stack<char>st;
        while(temp){
            string str = temp->data;
            
            for(char c : str){
                if(!st.empty() && st.top()==c){
                    st.pop();
                }
                else{
                    st.push(c);
                }
            }
            temp= temp->next;
        }
        
        return st.empty();
    }
};
