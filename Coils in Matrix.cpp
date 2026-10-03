class Solution {
	public:
	vector<vector<int>> formCoils(int n) {
		// code here
		int idx = 1;
		int top = 0, bottom = 4*n - 1, left = 0, right = 4*n - 1;
		vector<vector<int>> mat(4*n, vector<int>(4*n, 0));
		vector<vector<int>> result;
		vector<int>temp1, temp2;
		for (int i = 0; i<4*n; ++i) {
			for (int j = 0; j<4*n; ++j) {
				mat[i][j] = idx++;
			}
		}
		
		while (left <= right && top <= bottom) {
			while (top <= bottom) {
				for (int i = top; i <= bottom; ++i) {
					temp1.push_back(mat[i][left]);
				}
				for (int i = bottom; i >= top; --i) {
					temp2.push_back(mat[i][right]);
				}
				right--; left++;
				break;
			}
			while (left <= right) {
				for (int i = left; i <= right; ++i) {
					temp1.push_back(mat[bottom][i]);
				}
				for (int i = right; i >= left; --i) {
					temp2.push_back(mat[top][i]);
				}
				bottom--; top++;
				break;
			}
			while (top <= bottom) {
				for (int i = bottom; i >= top; --i) {
					temp1.push_back(mat[i][right]);
				}
				for (int i = top; i <= bottom; ++i) {
					temp2.push_back(mat[i][left]);
				}
				right--; left++;
				break;
			}
			while (left <= right) {
				for (int i = right; i >= left; --i) {
					temp1.push_back(mat[top][i]);
				}
				for (int i = left; i <= right; ++i) {
					temp2.push_back(mat[bottom][i]);
				}
				bottom--; top++ ;
				break;
			}
		}
		result.push_back(temp1);
		result.push_back(temp2);
		return result;
	}
};
