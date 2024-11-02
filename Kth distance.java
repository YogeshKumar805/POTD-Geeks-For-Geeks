class Solution {
    public boolean checkDuplicatesWithinK(int[] arr, int k) {
        HashSet<Integer> set=new HashSet<>();
        for(int i=0;i<arr.length;i++){
            if(set.contains(arr[i])){
                return true;
            }
            set.add(arr[i]);
            if(i>=k){
                set.remove(arr[i-k]);
            }
        }
        return false;
    }
}

