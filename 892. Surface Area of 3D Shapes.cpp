892. Surface Area of 3D Shapes
Easy
499
675
Companies
You are given an n x n grid where you have placed some 1 x 1 x 1 cubes. Each value v = grid[i][j] represents a tower of v cubes placed on top of cell (i, j).

After placing these cubes, you have decided to glue any directly adjacent cubes to each other, forming several irregular 3D shapes.

Return the total surface area of the resulting shapes.

Note: The bottom face of each shape counts toward its surface area.



Example 1:


Input: grid = [[1,2],[3,4]]
Output: 34
Example 2:


Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
Output: 32


solution

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
	int n = grid.size();
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == 0) continue;
			res += grid[i][j] * 6 - 2 * (grid[i][j] - 1);
			if (i < n - 1) res -= 2 * min(grid[i][j], grid[i+1][j]);
			if (j < n - 1) res -= 2 * min(grid[i][j], grid[i][j+1]);
		}
	}
	return res;
}
};
