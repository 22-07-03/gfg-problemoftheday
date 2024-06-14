class Solution {
  public:
    int padovanSequence(int n) {
        int k = 1e9 + 7;
        vector<long long>seq(n+1,0);
        seq[0]=seq[1]=seq[2]=1;
        
        for(int i =3;i<n+1;i++){
            seq[i] = (seq[i-2]+seq[i-3])%k;
        }
        
        return (seq[n]);
    }
};
