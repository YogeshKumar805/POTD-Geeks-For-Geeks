class Solution {
    
    private static final int [][] DIRECTION = new int [][]{
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };
    
    public int numOfWays(int n, int m) {
        // code here
        if (n == 1 && m == 1) {
            return 0;
        }
        long count = 0;
        long totalWhitePlace = n * m;
        
        // O(N * M)
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                long totalBlackPlace = totalWhitePlace - 1;
                // O(8)
                for (int [] dir : DIRECTION) {
                    int nextRow = dir[0] + row;
                    int nextCol = dir[1] + col;
                    if (nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < m) {
                        totalBlackPlace--;
                    }
                }
                count += totalBlackPlace;
            }
        }
        return (int)count;
    }
}
