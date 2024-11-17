class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        
        int n = arr.size();
        d = d % n; 
        rotate(arr.begin(), arr.begin() + d, arr.end());
 
    }
};
