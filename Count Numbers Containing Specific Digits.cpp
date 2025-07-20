class Solution {
  public:
    int countValid(int n, vector<int>& arr) {
        bool zero=false;
        for(int num:arr)
            if(num==0) zero=true;
        int m=arr.size();
        int total=9*pow(10,n-1);
        int discarded;
        discarded=zero?(10-m)*pow(10-m,n-1):(9-m)*pow(10-m,n-1);
        return total-discarded;
    }
};
