class Solution {
    static ArrayList<Integer> subarraySum(int[] arr, int target) {
        int n=arr.length;
        int currSum=0;
        int start=0;
        int end=0;
        ArrayList<Integer> res=new ArrayList<>();
        while(end<n){
            if(currSum<target){
                currSum+=arr[end++];
            }
            if(currSum==target){
                res.add(start+1);
                res.add(end);
                break;
            }
            if(currSum>target){
                currSum=0;
                start++;
                end=start;
            }
        }
        if(res.isEmpty()) res.add(-1);
        return res;
    }
}

