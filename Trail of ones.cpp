class Solution {
  public:
    
    int consec(int i, int prev,int n){
        if(i == n) return 1;
        
        int cnt = 0;
        
        cnt += consec(i+1, 0, n); //place 0
        
        if(prev == 0){
            cnt += consec(i+1, 1, n); //place 1
        }
        
        return cnt;
    }
    
    int countConsec(int n) {
        // code here
        int total = pow(2, n);
        int cons = consec(0,0,n);
        
        return total - cons;
    }
};

