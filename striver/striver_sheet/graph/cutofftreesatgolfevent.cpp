class Solution {
private:
    const int dr[4] = {0, 0, -1, 1};
    const int dc[4] = {-1, 1, 0, 0};
    bool valid(int r, int c, int m, int n) {
        return 0 <= r && r < m && 0 <= c && c < n;
    }
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size();
        int n = forest[0].size();
        vector<pair<int, int>> locations(1, {0, 0}); // locations we need to visit, in order
        
        vector<pair<int, pair<int, int>>> priority; // (tree num, location)
        
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (forest[r][c] > 1) {
                    priority.push_back({forest[r][c], {r, c}});
                }
            }
        }
        
        sort(priority.begin(), priority.end());
        
        for (pair<int, pair<int, int>> tree: priority) {
            locations.push_back(tree.second);
        }
        
        int tot_dist = 0;
        
        for (int loc = 0; loc + 1 < locations.size(); loc++) {
            // go from locations[loc] to locations[loc + 1]
            
            vector<vector<int>> dist(m, vector<int>(n, -1));
            
            pair<int, int> from = locations[loc];
            pair<int, int> to = locations[loc + 1];
            
            dist[from.first][from.second] = 0;
            
            queue<pair<int, int>> q;
            
            q.push(from);
            
            while (!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();
                
                for (int d = 0; d < 4; d++) {
                    int new_r = cur.first + dr[d];
                    int new_c = cur.second + dc[d];
                    
                    if (valid(new_r, new_c, m, n) && forest[new_r][new_c] != 0 && dist[new_r][new_c] == -1) {
                        dist[new_r][new_c] = dist[cur.first][cur.second] + 1;
                        q.push({new_r, new_c});
                    }
                }
            }
            
            if (dist[to.first][to.second] == -1) {
                return -1;
            } else {
                tot_dist += dist[to.first][to.second];
            }
        }
        
        return tot_dist;
    }
};