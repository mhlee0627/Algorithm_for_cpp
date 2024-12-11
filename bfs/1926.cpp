#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

queue<pair<int, int>> Q;
int board[501][501];
bool vis[501][501];
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};
int n, m;
int cnt;
int maxValue;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m ; j++) {
            if (vis[i][j] || board[i][j] == 0) continue;

            Q.push({i, j});
            vis[i][j] = 1;
            int curMax = 0;
            while(!Q.empty()) {
                pair<int, int> curPos = Q.front();
                Q.pop();
                curMax++;
                // cout << '(' << curPos.X << ", " << curPos.Y << ") -> ";
                for (int i = 0; i < 4; i++) {
                    int nx = curPos.X + dirX[i];
                    int ny = curPos.Y + dirY[i];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (vis[nx][ny] || board[nx][ny] == 0) continue;
                    Q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
            cnt++;
            // cout << "\ncurMax: " << curMax << "\n";
            maxValue = curMax > maxValue ? curMax : maxValue;
        }
    }
    cout << cnt << "\n" << maxValue;
    // cout << "cnt: " << cnt << ", maxValue: " << maxValue << endl;
}
