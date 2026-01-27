class Solution:
    def isWordExist(self, mat, word):
        n, m = len(mat), len(mat[0])

        # Early prune: if word contains more occurrences of a letter
        # than the board, no need to search.
        from collections import Counter
        board_count = Counter(sum(mat, []))
        word_count = Counter(word)
        for ch in word_count:
            if word_count[ch] > board_count.get(ch, 0):
                return False

        def dfs(i, j, idx):
            if idx == len(word):
                return True

            # boundary conditions or mismatch
            if i < 0 or j < 0 or i >= n or j >= m or mat[i][j] != word[idx]:
                return False

            temp = mat[i][j]
            mat[i][j] = "#"     # mark visited

            # explore 4 directions
            found = (
                dfs(i+1, j, idx+1) or
                dfs(i-1, j, idx+1) or
                dfs(i, j+1, idx+1) or
                dfs(i, j-1, idx+1)
            )

            mat[i][j] = temp    # restore
            return found

        # Try starting from each position
        for i in range(n):
            for j in range(m):
                if mat[i][j] == word[0]:
                    if dfs(i, j, 0):
                        return True

        return False
