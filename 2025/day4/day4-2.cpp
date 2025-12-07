#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> g;

int dx[8] = {-1,-1,-1, 0,0, 1,1,1};
int dy[8] = {-1, 0, 1,-1,1,-1,0,1};

int main() {
    ifstream file("day4.txt");
    string s;
    while (file >> s) g.push_back(s);

    n = g.size();
    m = g[0].size();
    vector<vector<int>> cnt(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] != '@') continue;
            int c = 0;
            for (int k = 0; k < 8; k++) {
                int nx = i + dx[k], ny = j + dy[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    if (g[nx][ny] == '@') c++;
                }
            }
            cnt[i][j] = c;
        }
    }

    queue<pair<int,int>> q;
    vector<vector<int>> inq(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '@' && cnt[i][j] < 4) {
                q.push({i, j});
                inq[i][j] = 1;
            }
        }
    }

    long long removed = 0;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        inq[x][y] = 0;
        if (g[x][y] != '@') continue;
        if (cnt[x][y] >= 4) continue;
        g[x][y] = '.';
        removed++;
        for (int k = 0; k < 8; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (g[nx][ny] == '@') {
                    cnt[nx][ny]--;
                    if (cnt[nx][ny] < 4 && !inq[nx][ny]) {
                        q.push({nx, ny});
                        inq[nx][ny] = 1;
                    }
                }
            }
        }
    }

    cout << removed << "\n";
    return 0;
}
