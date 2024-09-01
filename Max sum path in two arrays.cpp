class Solution {
  public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        // Code here
       int total=0,i=0,j=0,s1=0,s2=0;
       while(i<arr1.size() && j<arr2.size()){
           if(arr1[i]==arr2[j]){
               total+=(max(s1,s2)+arr1[i]);
               i++,j++;
               s1=0,s2=0;
           }
           else if(arr1[i]<arr2[j]){
               s1+=arr1[i];
               i++;
           }
           else{
               s2+=arr2[j];
               j++;
           }
       }
       while(i<arr1.size()){
           s1+=arr1[i];
           i++;
       }
       while(j<arr2.size()){
           s2+=arr2[j];
           j++;
       }
       total+=(max(s1,s2));
       return total;
    }
};
