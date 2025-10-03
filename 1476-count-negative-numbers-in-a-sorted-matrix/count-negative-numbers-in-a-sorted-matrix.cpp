class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int ans = 0;
        for (int i = rows - 1, j = 0; i >= 0 && j < cols;) {
            if (grid[i][j] < 0) {
                ans += cols - j;
                --i;
            } else
                ++j;
        }
        return ans;
    }
};