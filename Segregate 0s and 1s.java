class Solution {
    void segregate0and1(int[] arr) {
        
        int mid=0;
        int left=0;
        
        while(mid<arr.length){
            if(arr[mid]==0){
                int temp=arr[left];
                arr[left]=arr[mid];
                arr[mid]=temp;
                left++;
            }
            
            mid++;
        }
    }
}
