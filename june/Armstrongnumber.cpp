class Solution {
  public:
    string armstrongNumber(int n) {
       int n_copy= n ; 
       int ans =0 ;
       while(n!=0){
           int k = n%10;
           ans+= pow(k,3);
           n=n/10;
       }
       if(n_copy==ans){
           return "true";
       }
       
       return "false";
       
    }
};
