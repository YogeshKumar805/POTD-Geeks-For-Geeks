class Solution {
    int search(int[] arr, int key) {
        int n = arr.length;
        int i = 0, j = n - 1;
        int index = -1;
        while(i <= j){
            int mid = (i + j)/2;
            if(arr[mid] == key) return mid;
            if(arr[i] <= arr[j]){
                if(arr[i] <= key && key <= arr[j]){
                    if(arr[mid] < key) i = mid + 1;
                    else j = mid - 1;
                }else return -1;
            }else{ // arr[i] > arr[j]
                if(arr[mid] > arr[j]){ // sorted first part ( i -> mid)
                    if(arr[i] <= key && key <= arr[mid]) j = mid - 1;
                    else i = mid + 1;
                }else{  // sorted second part  (mid -> j)
                    if(arr[mid] <= key && key <= arr[j]) i = mid + 1;
                    else j = mid - 1;
                }
            }
        }
        
        return index;
    }
}
 
