class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int i = 0, j = 0, n = arr.size();
        while(j < n){
            if(arr[j] != 0 && i == j){
                i++;
                j++;
            }
            else if(arr[j] != 0){
                swap(arr[i],arr[j]);
                i++;
            }
            else{
                j++;
            }
        }
    }
};
