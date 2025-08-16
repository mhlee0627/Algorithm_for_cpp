#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[25][25];
bool dist[25][25];

int dirX[4][2] = {{1, -1}, {0,  0}, {-1, 1}, {1, -1}};
int dirY[4][2] = {{0,  0}, {1, -1}, {1, -1}, {1, -1}};

void clear_dist() {
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            dist[i][j] = false;
        }
    }
}

bool func(int x, int y, int color) {
    for (int i = 0; i < 4; i++) {
        clear_dist();
        queue<pair<int, int>> q;
        int maxd = 1;
        q.push({x, y});
        dist[x][y] = true;;

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            
            for (int j = 0; j < 2; j++) {
                int nx = cur.X + dirX[i][j];
                int ny = cur.Y + dirY[i][j];
                if (nx < 0 || nx >= 19 || ny < 0 || ny >= 19) continue;
                if (dist[nx][ny] == true || board[nx][ny] != color) continue;

                maxd++;
                q.push({nx, ny});
                dist[nx][ny] = true;
            }
        }

        if (maxd == 5) return true;
    }

    return false;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            cin >> board[i][j];
        }
    }

    for (int j = 0; j < 19; j++) {
        for (int i = 0; i < 19; i++) {
            if (board[i][j] == 0) continue;

            if (func(i, j, board[i][j])) {
                cout << board[i][j] << '\n';
                cout << i+1 << ' ' << j+1 << '\n';
                return 0;
            }
        }
    }

    cout << 0 << '\n';
}