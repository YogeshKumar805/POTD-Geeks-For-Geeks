class Solution {
  public:
    int minimumStep(int n) {
        // code here
        int ans = 0 ;
        while(n != 1){
            if(n>= 3){
                ans += n%3 ;
                ans ++ ;
                n /= 3 ;
            }
            else{
            n -= 1 ;
            ans++ ;
            }
        }
        return ans ;
    }
};
