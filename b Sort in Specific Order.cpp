class Solution {
  public:
    static bool comparator(int &a, int &b){
        if((a&1) and (b&1)){
            // both are odd, larger odd should come first
            return a>b;
        }
        else if(!(a&1) and !(b&1)){
            // both of them are even, larger even should come later
            return a<b;
        }
        // one of them is odd, if a is odd then the order is correct otherwise swap
        return (a&1);
    }
    void sortIt(vector<int>& arr) {
        sort(arr.begin(), arr.end(), comparator);
    }
};
