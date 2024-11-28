class Solution {
  public:
    int myAtoi(char *s) {
        // Your code here
        int isneg = 0; // track number of time - sign
        int i = 0 ;  // indexing
        string res =""; // O(n)  // res string
        while(s[i] != '/0'){
              // Leading + or leading white Space handle
            if((s[i] == '+' || s[i] == ' ') && res.size()==0) i++;
            // leading white Space handle
            else if(s[i] == '0' && res.size() == 0) i++;
                else{
                // We initally we found negitive sign
                    if(s[i] == '-' && res.size()==0) isneg++;
                // if we encounter numeric value and add into result string
                else if(s[i] >= '0' && s[i] <= '9') res += s[i];
                // if we encounter any alphanumeric
                else break;
                i++;
                }
            // if we encounter two negative sign
             if(isneg>1) return 0;    
            }
            
        if(res.size()==0) return 0;
        
       if(res.size() > 9){
           if(isneg) return INT_MIN;
           else return INT_MAX;
       }
       
       int ans = stoi(res);  // O(n)
       if(isneg) ans*=-1;
       return ans;
    }
};
