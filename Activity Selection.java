class Solution {
    public int activitySelection(int[] start, int[] finish) {
        int[][] arr=new int[start.length][2];
        for(int i=0;i<start.length;i++){
            arr[i]=new int[]{start[i],finish[i]};
        }
        Arrays.sort(arr,(a,b)->Integer.compare(a[1],b[1]));
        int end=-1;
        int count=0;
        for(int i=0;i<start.length;i++){
            if(end<arr[i][0]){
                count++;
                end=arr[i][1];
            }
        }
        return count;
    }
}
