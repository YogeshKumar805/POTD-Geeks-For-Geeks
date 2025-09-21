class Solution {
  public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0, n = heights.size();
        
        for (int i = 0; i <= n; i++) {
            int h = (i == n ? 0 : heights[i]);
            while (!st.empty() && h < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int width = (st.empty() ? i : i - st.top() - 1);
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }
    
    int maxArea(vector<vector<int>> &mat) {
        if (mat.empty()) return 0;
        int m = mat.size(), n = mat[0].size();
        
        vector<int> heights(n, 0);
        int maxAreaRect = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                heights[j] = (mat[i][j] == 0 ? 0 : heights[j] + 1);
            }
            maxAreaRect = max(maxAreaRect, largestRectangleArea(heights));
        }
        
        return maxAreaRect;
    }
};

