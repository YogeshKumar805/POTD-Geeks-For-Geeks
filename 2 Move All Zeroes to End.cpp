class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int cnt=0;
        int start=0;
        int n=arr.size();
        for(auto &i: arr){
            if(i==0){
               cnt++; 
            }
            else{
               arr[start]=i;
               start++;
            }
        }
        int end=n-1;
        while(cnt--){
           arr[end]=0;
           end--;
        }
    }
}; 
