class Solution {
  public:

    string printString(string s, char ch, int count) {
        // Your code goes here
        int n=s.length();
        int flag=0;
        
        //Traverse in string
        for(int i=0;i<n;i++){
            if(s[i] == ch){
                flag++;
            }
            // When the required occurrence is found
            if(flag == count){
                if(i+1 < n){
                    return s.substr(i+1,n-i-1);
                }
                else{
                    return ""; //Remaining substring is empty
                }
            }
        }
          // If the character did not appear the required number of times
          return "";
    }
};
