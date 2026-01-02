class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
         int n = arr.size();
         int i=0;
         int j=n-1;

         for(int k=0;k<=j;k++){
               if (arr[k]==0){
                    swap(arr[i],arr[k]);
                    i++;
               }
               else if (arr[k]==2){
                    swap(arr[j],arr[k]);
                    j--;
                          k--;  
               }
         }
    

    }
};
