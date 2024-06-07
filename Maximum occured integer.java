class Solution {
    // Function to find the maximum occurred integer in all ranges.
    public static int maxOccured(int n, int l[], int r[], int maxx) {
        
        int max=Integer.MIN_VALUE;
        int index=0;
        int[] freq=new int[maxx+2];
   
       for(int i=0;i<n;i++){
           freq[l[i]]++;
           freq[r[i]+1]--;
       }
 
      for(int i=1;i<freq.length;i++){
          freq[i]=freq[i-1]+freq[i];
            if(freq[i]==max){
                if(i<index){
                    index=i;
                }
            }
            else if(freq[i]>max){
                max=freq[i];
                index=i;
            }
        }
        return index;   
    }
}

