433212class Solution {
    // Function to solve Sudoku
    static void solveSudoku(int[][] mat) {
        solve(mat);
    }
    
    // Function to check if placing 'num' at mat[row][col] is valid
    static boolean isValid(int[][] mat, int row, int col, int num) {
        // Check row and column
        for (int i = 0; i < 9; i++) {
            if (mat[row][i] == num || mat[i][col] == num) {
                return false;
            }
        }
        
        // Check 3x3 sub-grid
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (mat[startRow + i][startCol + j] == num) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    // Recursive function to solve Sudoku using backtracking
    static boolean solve(int[][] mat) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (mat[row][col] == 0) {  // Empty cell found
                    for (int num = 1; num <= 9; num++) {
                        if (isValid(mat, row, col, num)) {
                            mat[row][col] = num; // Place the number

                            if (solve(mat)) {  // Recursively try to solve
                                return true;
                            }
                            mat[row][col] = 0; // Backtrack if no solution found
                        }
                    }
                    return false; // If no number fits, return false
                }
            }
        }
        return true; // All cells filled correctly
    }
}

