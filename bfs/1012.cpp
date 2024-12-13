#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

queue<pair<int, int>> Q;
int board[50][50];
bool vis[50][50];
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};
int M, N, T, K;
int cnt;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> M >> N >> K;
        
        // clear board and vis
        cnt = 0;
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                board[n][m] = 0;
                vis[n][m] = 0;
            }
        }

        // set board
        for (int j = 0; j < K; j++) {
            int x = 0, y = 0;
            cin >> y >> x;
            board[x][y] = 1;
        }

        // check board
        // cout << "check board\n";
        // for (int i = 0; i < N; i++) {
        //     for (int j = 0; j < M; j++) {
        //         cout << board[i][j] << ", ";
        //     }
        //     cout << "\n";
        // }

        // bfs
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (vis[i][j] || board[i][j] != 1) continue;
                Q.push({i, j});
                vis[i][j] = true;
                cnt++;
                // cout << "for in cnt: " << cnt << "\n";

                while(!Q.empty()) {
                    pair<int, int> curPos = Q.front();
                    Q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = curPos.X + dirX[k];
                        int ny = curPos.Y + dirY[k];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                        if (vis[nx][ny] || board[nx][ny] != 1) continue;
                        Q.push({nx, ny});
                        vis[nx][ny] = true;
                    }
                }
            }
        }

        // check vis
        // cout << "check vis\n";
        // for (int i = 0; i < N; i++) {
        //     for (int j = 0; j < M; j++) {
        //         cout << vis[i][j] << ", ";
        //     }
        //     cout << "\n";
        // }

        cout << cnt << "\n";
    }

}


