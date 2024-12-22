class Solution {
    public static boolean matSearch(int mat[][], int x) {
        // your code here
        int m=mat.length;
        int n=mat[0].length;
        int i=0,j=n-1;
        while(i<m&&j>=0){
            if(mat[i][j]<x){
                i++;
            }else if(mat[i][j]>x){
                j--;
            }else{
                return true;
            }
        }
        return false;
    }
}
