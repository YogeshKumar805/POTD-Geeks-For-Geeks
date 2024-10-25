class Solution {
    public static ArrayList<Integer> alternateSort(int[] arr) {
        // Your code goes here
        Arrays.sort(arr);
        ArrayList<Integer> list = new ArrayList<>();
        int i=0; 
        int j=arr.length-1;
        while(i<=j){
            list.add(arr[j--]);
            if(i<=j){
                list.add(arr[i++]);
            }
        }
        return list;
    }
}
