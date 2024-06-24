class Solution {
  public:
    long long sumMatrix(long long n, long long q) {
        //diagonals =2*n-1;
        //diagonal element=n+1;
        //difference=n+1-q;
        return max(0LL,(n-abs(n+1-q)));
    }
};
