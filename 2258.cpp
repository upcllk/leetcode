#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        int left = 0, right = mn;
        bool existPathWhenBreak = false;
        while(left < right) {
            int mid = left + ((right - left) << 1);
            vector<vector<int>> fireGrid = getFireGridAfter(grid, mid);
            if(existPath(fireGrid, mid)) {
                existPathWhenBreak = true;
                left = mid;
            }
            else {
                existPathWhenBreak = false;
                right = mid - 1;
            }
        }
        if(existPathWhenBreak) {
            if(right == mn) {
                return 1e9;
            }
            return left;
        }
        else {
            return -1;
        }

    }
};

vector<vector<int>> dirVec = {
    {-1, 0},
    {1, 0},
    {0, 1},
    {0, -1}
};

vector<vector<int>> getFireGridAfter(const vector<vector<int>>& grid, int second) {
    if(second <= 0) {
        return grid;
    }
    const int m = grid.size(), n = grid[0].size();
    vector<vector<int>> res = grid;
    queue<pair<int, int>> que;
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(grid[i][j] == 1) {
                que.push({i, j});
            }
        }
    }

    while(!que.empty()) {
        pair<int, int> cur = que.front();
        que.pop();
        for(auto dir : dirVec) {
            int newX = cur.first + dir[0];
            int newY = cur.second + dir[1];
            if(newX >= 0 && newX < m && newY >= 0 && newY < n) {
                if(grid[newX][newY] == 0) {
                    res[newX][newY] = 1;
                }
            }
        }
    }
    return getFireGridAfter(res, second - 1);
}

int main() {
    Solution solution;

    return 0;
}