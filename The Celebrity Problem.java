class Solution {
    public int celebrity(int[][] mat) {
        int n = mat.length, j = 0;
        for(int i=0;i<n;i++){
            if(knows(mat, j , i)) j = i;
        }
        for(int i=0;i<n;i++){
            if(j != i && (knows(mat, j, i) || !knows(mat, i, j))) return -1;
        }
        return j;
    }
    private boolean knows(int[][] m, int a, int b){
        return m[a][b] == 1;
    }
}
