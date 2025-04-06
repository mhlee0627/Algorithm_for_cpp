#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;
queue<pair<int, int>> q;
string board[605];
bool vis[605][605];
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};
int cnt;

void bfs(int x, int y) {
    q.push({x, y});
    vis[x][y] = 1;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dirX[i];
            int ny = cur.Y + dirY[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny] == 1) continue;
            if (board[nx][ny] == 'X') continue;

            if (board[nx][ny] == 'P') cnt++;
            q.push({nx, ny});
            vis[nx][ny] = 1;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'I') {
                bfs(i, j);
                
                if (cnt == 0) cout << "TT\n";
                else cout << cnt << '\n';

                return 0;
            }
        }
    }
}