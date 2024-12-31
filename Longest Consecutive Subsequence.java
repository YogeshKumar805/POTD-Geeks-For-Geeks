class Solution {

 

    // Function to return length of longest subsequence of consecutive integers.

    public int longestConsecutive(int[] arr) {

        int max=0;

        for(int i:arr) max=Math.max(max,i);

        int arr1[]=new int[max+1];

        for(int i:arr){

            arr1[i]=1;

        }

        int count=0;

        int maxc=0;

        for(int i:arr1){

           if(i==1){ count++;}

           else{ maxc=Math.max(maxc,count);count=0;}

        }

        maxc=Math.max(maxc,count);

        return maxc;

        // code here

    }

}
