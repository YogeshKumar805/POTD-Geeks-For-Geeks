class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int n = arr.size(), num1 = arr[0], num2 = -1;
        int lo1 = 0, lo2 = 0;
        int fo1 = 0, fo2 = 0;
        
        int maxm = 0;
        for(int i = 1 ; i < n ; i++ ){
            if(arr[i] != num1 && num2 == -1){
                num2 = arr[i];
                fo2 = i;
                lo2 = i;
            }
            else if(arr[i] == num1) lo1 = i;
            else if(arr[i] == num2) lo2 = i;
            else {
                maxm = max(maxm, i - min(fo1, fo2));
                if(lo1 > lo2){
                    fo1 = lo2 + 1;
                    num2 = arr[i];
                    fo2 = lo2 = i;
                } else {
                    fo2 = lo1 + 1;
                    num1 = arr[i];
                    fo1 = lo1 = i;
                }
            }
        }
        maxm = max(maxm, n - min(fo1, fo2));
        return maxm;
    }
};
