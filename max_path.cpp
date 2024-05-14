/* 1219: Path with maximum gold

 In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.
 Return the maximum amount of gold you can collect under the conditions:
    -Every time you are located in a cell you will collect all the gold in that cell.
    -From your position, you can walk one step to the left, right, up, or down.
    -You can't visit the same cell more than once.
    -Never visit a cell with 0 gold.
    -You can start and stop collecting gold from any position in the grid that has some gold.

Example 1:

Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
Output: 24
Explanation:
[[0,6,0],
 [5,8,7],
 [0,9,0]]
Path to get the maximum gold, 9 -> 8 -> 7.

Example 2:

Input: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
Output: 28
Explanation:
[[1,0,7],
 [2,0,6],
 [3,4,5],
 [0,3,0],
 [9,0,20]]
Path to get the maximum gold, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.
 */


class Solution {
public:
    int get_gold_rec(vector<vector<int>>& grid, int i, int j) {
        // cout<<i<<" "<<j<<endl;
        if (i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0) {
            return 0;
        }

        if (grid[i][j] == 0) {
            return 0;
        }

        int g = grid[i][j];
        grid[i][j] = 0;

        int x = g + std::max(std::max(get_gold_rec(grid, i + 1, j),
                                      get_gold_rec(grid, i - 1, j)),
                             std::max(get_gold_rec(grid, i, j - 1),
                                      get_gold_rec(grid, i, j + 1)));
        grid[i][j] = g;
        return x;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int max_gold = 0;
        int cg = 0;
        int i = 0, j = 0;

        for (int gi = 0; gi < grid.size(); gi++) {
            for (int gj = 0; gj < grid[i].size(); gj++) {
                max_gold = max(max_gold, get_gold_rec(grid, gi, gj));
            }
        }
        // max_gold = 0;
        // max_gold = get_gold_rec(grid,i,j);
        // cout<<grid[i].size();
        return max_gold;
    }
};


int main(){
    Solution s;
    std::vector<vector<int>> grid {{1,0,7},{2,0,6},{3,4,5},{0,3,0},{9,0,20}};
    cout<<s.getMaximumGold(grid);
    return 0;
}