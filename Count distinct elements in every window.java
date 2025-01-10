class Solution {
    ArrayList<Integer> countDistinct(int arr[], int k) {
        // code here
         int count = 0;
         int n = arr.length;
         ArrayList<Integer> list = new ArrayList<>();
      
         
         for(int i=0; i<=n-k; i++){
        HashSet<Integer> set = new HashSet<>();
             int j = i;
             
             while(j < i+k){
                 set.add(arr[j]);
                 j++;
             }
            list.add(set.size()); 
         }
          
        
        
        return list;
    }
}
