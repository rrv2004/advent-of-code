#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> g;
vector<vector<int>> vis;

int dx[8] = {-1,-1,-1, 0,0, 1,1,1};
int dy[8] = {-1, 0, 1,-1,1,-1,0,1};

int accessible = 0;

void dfs(int x, int y) {
    vis[x][y] = 1;

    int neighbors = 0;
    for (int k = 0; k < 8; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (g[nx][ny] == '@')
                neighbors++;
        }
    }

    if (neighbors < 4)
        accessible++;

    for (int k = 0; k < 8; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (!vis[nx][ny] && g[nx][ny] == '@') {
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    ifstream file("day4.txt");
    string s;
    while (file >> s) g.push_back(s);

    n = g.size();
    m = g[0].size();

    vis.assign(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && g[i][j] == '@') {
                dfs(i, j);
            }
        }
    }

    cout << accessible << "\n";
    return 0;
}
