class Solution {
  public:
    virtual bool isSumOfConsecutive(int n){
      return n&(n-1);
    }
};
