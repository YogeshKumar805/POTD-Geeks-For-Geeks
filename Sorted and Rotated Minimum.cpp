class Solution {
  public:
    int findMin(vector<int>& arr) {
       int st=0,end=arr.size()-1;
       while(st<end){
           int mid=st+(end-st)/2;
           if(arr[mid]>arr[end]){
               st=mid+1;
           }else end=mid;
           
       }
       return arr[st];
    }
};
