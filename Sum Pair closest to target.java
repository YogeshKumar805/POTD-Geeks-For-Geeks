 class Solution {
    public List<Integer> sumClosest(int[] arr, int target) {
        Arrays.sort(arr);
        List<Integer> res = new ArrayList<>();
        int l = 0;
        int h = arr.length-1;
        int a = -1;
        int b = -1;
        int maxDiff = 0;
         
        while(l < h){
            int sum = arr[l] + arr[h];
            
            if(sum <= target){
                if(Math.abs(target - sum) < Math.abs(target - (a + b))
                || (sum == a + b && Math.abs(arr[l] - arr[h]) > maxDiff)){
                    a = arr[l];
                    b = arr[h];
                    maxDiff = Math.abs(arr[l] - arr[h]);
                }
                l++;
            }else{
                if((a == -1 && b == -1) || Math.abs(target - sum) < Math.abs(target - (a + b))
                || (sum == a + b && Math.abs(arr[l] - arr[h]) > maxDiff)){
                    a = arr[l];
                    b = arr[h];
                    maxDiff = Math.abs(arr[l] - arr[h]);
                }
                h--;
            }
        }
        
        if(a != -1 && b != -1){
            res.add(a);
            res.add(b);
        }
        
        return res;
    }
}
