class Solution {
    static int minJumps(int[] arr) {
        // your code here
        
        int jumps=0;
        int currentIndex=0;
        int farIndex=0;
        
        //if arr length is 0 or 1st element is 0
        if(arr.length==0 || arr[0]==0) return -1;
        
        //for length 1
        else if(arr.length==1) return 1;
        
        else {
            for(int i=0; i<arr.length-1; i++){
                farIndex=Math.max(farIndex, i+arr[i]);
                
                if(i==currentIndex){
                    jumps++;
                    currentIndex=farIndex;
                    
                    if(currentIndex>=arr.length-1) return jumps;
                    
                }
                
            }
        }
        return -1;
    }
}

