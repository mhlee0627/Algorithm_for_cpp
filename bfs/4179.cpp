#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

queue<pair<int, int>> jQ;
queue<pair<int, int>> fQ;
char board[1001][1001];
int jdist[1001][1001];
int fdist[1001][1001];
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};
int R, C;
int minValue;
int maxValue;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            jdist[i][j] = -1;
            fdist[i][j] = -1;
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
            if (board[i][j] ==  'J') {
                jQ.push({i, j});
                jdist[i][j] = 0;
            }
            if (board[i][j] == 'F') {
                fQ.push({i, j});
                fdist[i][j] = 0;
            }
        }
    }

    while(!fQ.empty()) {
        pair<int, int> curPos = fQ.front();
        fQ.pop();
        for (int i = 0; i < 4; i++) {
            int nx = curPos.X + dirX[i];
            int ny = curPos.Y + dirY[i];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (board[nx][ny] == '#' || fdist[nx][ny] >= 0) continue;
            fQ.push({nx, ny});
            fdist[nx][ny] = fdist[curPos.X][curPos.Y] + 1;
        }
    }

    // cout << "fdist\n";
    // for (int i = 0; i < R; i++) {
    //     for (int j = 0; j < C; j++) {
    //         cout << fdist[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    while(!jQ.empty()) {
        pair<int, int> curPos = jQ.front();
        jQ.pop();
        for (int i = 0; i < 4; i++) {
            int nx = curPos.X + dirX[i];
            int ny = curPos.Y + dirY[i];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
                // exit!!!!!
                cout << jdist[curPos.X][curPos.Y] + 1;
                return 0;
            }
            if (board[nx][ny] == '#' || jdist[nx][ny] >= 0) continue;
            jdist[nx][ny] = jdist[curPos.X][curPos.Y] + 1;
            if (fdist[nx][ny] != -1 && jdist[nx][ny] >= fdist[nx][ny]) {
                jdist[nx][ny] = -1;
                continue;
            }
            jQ.push({nx, ny});
        }
    }

    // cout << "jdist\n";
    // for (int i = 0; i < R; i++) {
    //     for (int j = 0; j < C; j++) {
    //         cout << jdist[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << "IMPOSSIBLE";
}