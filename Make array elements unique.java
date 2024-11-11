class Solution {
    public int minIncrements(int[] arr) {
        // Code here
        // int ans =0;
        // Arrays.sort(arr);
        // HashSet<Integer> set = new HashSet<>();;
        // for(int i =0 ;i< arr.length ; i++){
        //     while(set.contains(arr[i])){
        //         arr[i]++;
        //         ans++;
        //     }
        //     set.add(arr[i]);
        // }
        // return ans ;
        int ans =0;
        Arrays.sort(arr);
        for(int i =1 ; i< arr.length ; i++){
            if(arr[i-1] >= arr[i]){
                int increament = arr[i-1] - arr[i] +1;
                ans += increament;
                arr[i] = arr[i-1] +1;
            }
        }
        return ans;
    }
}
