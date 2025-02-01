class Solution {
    static public boolean isWordExist(char[][] mat, String word) {
        int n = mat.length, m = mat[0].length;
        boolean[][] visited = new boolean[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == word.charAt(0) && dfs(mat, word, i, j, 0, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
    private static boolean dfs(char[][] mat, String word, int i, int j, int index, boolean[][] visited) {
        if (index == word.length()) return true;
        if (i < 0 || i >= mat.length || j < 0 || j >= mat[0].length || visited[i][j] || mat[i][j] != word.charAt(index)) {
            return false;
        }
        visited[i][j] = true;
        boolean found = dfs(mat, word, i + 1, j, index + 1, visited) ||
                        dfs(mat, word, i - 1, j, index + 1, visited) ||
                        dfs(mat, word, i, j + 1, index + 1, visited) ||
                        dfs(mat, word, i, j - 1, index + 1, visited);

        visited[i][j] = false; // Backtrack
        return found;
    }
}

