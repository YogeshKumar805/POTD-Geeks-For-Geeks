class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int n=arr.size();
        int i=0, j=n-1;
        while(i<j){
            while(i<j && arr[i]==0){
                i++;
            }
            while(i<j && arr[j]==1){
                j--;
            }
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
};
