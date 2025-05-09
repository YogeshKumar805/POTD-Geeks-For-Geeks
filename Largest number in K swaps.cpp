class Solution {
  public:
    // Function to find the largest number after k swaps.
    string findMaximumNum(string& s, int k) {
         
        int sz = s.length() ; 
         
        for(int l = 0 ; l < sz ; l++){
           
            char maxi = s[l];
            int idx = l;
            for(int r = l+1 ; r < sz ;r++){
                if(maxi <= s[r]){
                    maxi = s[r];
                    idx = r;
                }
            }
            if(s[idx]!=s[l]){
                swap(s[l],s[idx]);
                k--;
                if(k==0) return s;
            }
        }
        return s;
    }
};

