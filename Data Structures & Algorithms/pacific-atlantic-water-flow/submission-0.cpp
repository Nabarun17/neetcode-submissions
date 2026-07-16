#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <string>
#include <unordered_set>
#include <deque>
#include <numeric>
#include <tuple>
#include <climits>
#include <cmath>
#include <random>
#include <type_traits>
#include <iterator>
#include <iomanip>
#include <regex>
#include <cctype>
#include <exception>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& heights, vector<vector<int>>& reachable, int r, int c, int prevHeight) {
        int rows = heights.size();
        int cols = heights[0].size();

        if (r < 0 || r >= rows || c < 0 || c >= cols || reachable[r][c] || heights[r][c] < prevHeight) {
            return;
        }

        reachable[r][c] = 1;
        dfs(heights, reachable, r + 1, c, heights[r][c]);
        dfs(heights, reachable, r - 1, c, heights[r][c]);
        dfs(heights, reachable, r, c + 1, heights[r][c]);
        dfs(heights, reachable, r, c - 1, heights[r][c]);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};

        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> pacific(rows, vector<int>(cols, 0));
        vector<vector<int>> atlantic(rows, vector<int>(cols, 0));

        for (int c = 0; c < cols; c++) {
            dfs(heights, pacific, 0, c, heights[0][c]);
            dfs(heights, atlantic, rows - 1, c, heights[rows - 1][c]);
        }

        for (int r = 0; r < rows; r++) {
            dfs(heights, pacific, r, 0, heights[r][0]);
            dfs(heights, atlantic, r, cols - 1, heights[r][cols - 1]);
        }

        vector<vector<int>> result;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (pacific[r][c] && atlantic[r][c]) {
                    result.push_back({r, c});
                }
            }
        }
        return result;
    }
};