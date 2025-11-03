class Solution {
public:
    // Helper: Largest Rectangle in Histogram (LeetCode 84)
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();
        
        for (int i = 0; i <= n; i++) {
            int currHeight = (i == n) ? 0 : heights[i];
            
            while (!st.empty() && currHeight < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            
            st.push(i);
        }
        return maxArea;
    }

    // Main function: Maximal Rectangle (LeetCode 85)
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxArea = 0;

        for (int i = 0; i < rows; i++) {
            // Build histogram heights for this row
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }

            // Compute the largest area for this histogram
            int area = largestRectangleArea(heights);
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};
