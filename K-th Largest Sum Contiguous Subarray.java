import java.util.*;
import java.util.Collections;

class Solution {
    public static int kthLargest(int[] arr, int k) {
        // code here
        List<Integer> sums=new ArrayList<>();
        for(int i=0;i<arr.length;i++){
            int sum=0;
            for(int j=i;j<arr.length;j++){
                sum+=arr[j];
                sums.add(sum);
            }
        }
        Collections.sort(sums,Collections.reverseOrder());
        return sums.get(k-1);
    }
}

