class Solution {
  public:
   int minRepeats(string A, string B) {
        string rep = A;
        int cnt=1;
        while(A.size()<B.size()){
            A+=rep;
            cnt++;
        }
       
        if(A.find(B)!=-1) return cnt;
         A+=rep;
         cnt++;
        if(A.find(B)!=-1) return cnt;
        return -1;
    }
};
