#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> sol(rows, vector<int>(cols));
        
        k = k % cols; // Reduce k to within the range of column indices
        int n = cols;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int c = (j - k);
                if (c < 0) c = n + c;
                sol[i][c] = mat[i][j];
            }
        }
        
        return sol;
    }
};  

 
