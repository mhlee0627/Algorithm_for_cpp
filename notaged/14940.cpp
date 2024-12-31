#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[1000][1000];
int dist[1000][1000];
queue<pair<int, int>> Q;
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};
int n, m;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        dist[i][j] = -1;

    pair<int, int> start;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                start = {i, j};
                dist[i][j] = 0;
            }
            else if (board[i][j] == 0) {
                dist[i][j] = 0;
            }
        }
    }

    Q.push(start);
    while (!Q.empty()) {
        pair<int, int> curPos = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = curPos.X + dirX[i];
            int ny = curPos.Y + dirY[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (board[nx][ny] != 1 || dist[nx][ny] >= 0) continue;
            Q.push({nx, ny});
            dist[nx][ny] = dist[curPos.X][curPos.Y] + 1;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}