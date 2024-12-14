#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

queue<pair<int, int>> Q;
char board [100][100];
bool vis[100][100];
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};
int N;
int cnt;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (vis[i][j]) continue;
            Q.push({i, j});
            vis[i][j] = true;
            cnt++;
            // cout << "for: " << board[i][j] << "| i,j: " << i << " " << j << "\n";

            while(!Q.empty()) {
                pair<int, int> curPos = Q.front();
                Q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = curPos.X + dirX[dir];
                    int ny = curPos.Y + dirY[dir];
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if (vis[nx][ny] || board[nx][ny] != board[i][j]) continue;
                    Q.push({nx, ny});
                    vis[nx][ny] = true;
                }
            }
        }
    }

    cout << cnt << " ";

    // clear vis
    cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            vis[i][j] = 0;;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (vis[i][j]) continue;
            Q.push({i, j});
            vis[i][j] = true;
            cnt++;
            // cout << "for: " << board[i][j] << " | i,j: " << i << " " << j << "\n";

            while(!Q.empty()) {
                pair<int, int> curPos = Q.front();
                Q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = curPos.X + dirX[dir];
                    int ny = curPos.Y + dirY[dir];
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if (vis[nx][ny]) continue;
                    if (board[i][j] == 'B' && board[nx][ny] != 'B') continue;
                    if (board[i][j] != 'B' && board[nx][ny] == 'B') continue;
                    Q.push({nx, ny});
                    vis[nx][ny] = true;
                }
            }
        }
    }

    cout << cnt;
}