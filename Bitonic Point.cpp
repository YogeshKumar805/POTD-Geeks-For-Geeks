class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        // code here
        return *max_element(arr.begin(),arr.end());
    }
}; 
