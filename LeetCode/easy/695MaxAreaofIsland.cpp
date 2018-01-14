/*Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]

Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.

Example 2:

[[0,0,0,0,0,0,0,0]]

Given the above grid, return 0.

Note: The length of each dimension in the given grid does not exceed 50. */
/*无脑 DFS*/
class Solution {
public:
    int max = 0;
    bool vis[50][50] = { 0 };
    void dfs(vector<vector<int>>& grid, int i, int j, int& cur)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return;
        if (vis[i][j])
            return;
        vis[i][j] = true;
        if (grid[i][j] == 0)
            return;
        cur += grid[i][j];
        max = std::max(max, cur);
        dfs(grid, i - 1, j, cur);
        dfs(grid, i + 1, j, cur);
        dfs(grid, i, j - 1, cur);
        dfs(grid, i, j + 1, cur);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {

        int i, j;
        int cur;
        for (i = 0; i < grid.size(); ++i) {
            for (j = 0; j < grid[0].size(); ++j) {
                cur = 0;
                dfs(grid, i, j, cur);
            }
        }
        return max;
    }
};
