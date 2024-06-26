class Solution {
    public int findCoverage(int[][] matrix) {
        // code here
        int result = 0;
        
        for(int i = 0; i < matrix.length; i++) {
            for(int j = 0; j < matrix[i].length; j++) {
                if(matrix[i][j] == 0) {
                    // Left
                    if(((j - 1) >= 0) && matrix[i][j - 1] == 1) {
                        result++;    
                    }
                    
                    // right
                    if(((j + 1) < matrix[i].length) && matrix[i][j + 1] == 1) {
                        result++;    
                    }
                    
                    // up
                    if((((i - 1) >= 0) && matrix[i - 1].length > j) && matrix[i - 1][j] == 1) {
                        result++;
                    }
                    
                    // down
                    if((((i + 1) < matrix.length) && matrix[i + 1].length > j) && matrix[i + 1][j] == 1) {
                        result++;
                    }
                }
            }
        }
        return result;
    }
}
