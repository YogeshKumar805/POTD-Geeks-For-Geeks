class Solution {
  public:
    char posInfinite(string &s, int pos) {
        // code here
        int len = s.size();
        int i = 1;
        while(len<pos){
            len = 2*len +i;
            i++;
        }
        
        while(i>1){
            i--;
            long long pl = (len - i)/2;
            if(pos<=pl){
                
            }
            else if(pos<=pl+i){
                return '$';
            }
            else{
                long long r = pos - (pl +i);
                pos = pl - r+1;
            }
            len = pl;
        }
        return s[pos-1];
    }
};
