class Solution {
  public:
    bool divby13(string &s) {
        // code here
        //first test case
        // 2%13=2
        // then include 2 for next
        // 29%13= 3 remender
        // next become 31%13=5 remender
        // next become 51%13=12 remender
        // next become 122%13=5remender
        // next become 58%13=6 remender
        // next become 65%13=0 remender
        
        // at last if we get remender ==0 means divible by 13
        
        int remender=0;
        for(int i=0;i<s.size();i++){
            if(remender!=0){
                int value=remender*10+(s[i]-'0');
                remender=value%13;
            }
            else{
            remender=(s[i]-'0');
            }
        }
        return remender==0;
        
    }
};

