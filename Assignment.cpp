#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> G(n, vector<int>(n));
        vector<int> degree(n);
        for (auto& r : roads) {
            int u = r[0], v = r[1];
            G[u][v] = G[v][u] = 1;
            degree[u]++;
            degree[v]++;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ans = max(ans, degree[i] + degree[j] - G[i][j]);
            }
        }
        return ans;
    }
};

int main() {
    int n = 4;
    vector<vector<int>> roads = {{0, 1}, {0, 3}, {1, 2}, {1, 3}};
    Solution solution;
    int result = solution.maximalNetworkRank(n, roads);
    cout << "Maximal network rank: " << result << endl;

    return 0;
}
