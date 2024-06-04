 string binaryNextNumber(string s) {
         int numzeros = 0;
    for (int i = s.size() - 1; i >= 0; i--) {  // start from the end
        if (s[i] == '0') {
            s[i] = '1';
            break;
        } else {
            s[i] = '0';
            numzeros++;
        }
    }

    if (numzeros == s.size()) {
        return '1' + s;  // add '1' at the beginning if all bits are '1'
    }
    
    string ans=""; int index = -1;
     
     for(int i =0;i<s.size();i++){
         if(s[i]=='1'){
            index = i;  break;
         }
     }
     
     ans = s.substr(index);
     return ans;
    
    }
