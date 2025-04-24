#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, l, r;
int board[55][55];
int vis[55][55];
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};

void clear_vis() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            vis[i][j] = 0;
        }
    }
}

void print_brd() {
    cout << "print brd\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void bfs(int x, int y, int lab) {
    int sum = 0;
    vector<pair<int, int>> vec;
    queue<pair<int, int>> q;
    q.push({x, y});
    sum += board[x][y];
    vec.push_back({x, y});
    vis[x][y] = lab;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = dirX[i] + cur.X;
            int ny = dirY[i] + cur.Y;
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (vis[nx][ny] > 0) continue;

            int mv_flag = abs(board[cur.X][cur.Y] - board[nx][ny]);
            if (mv_flag < l || mv_flag > r) continue;

            q.push({nx, ny});
            sum += board[nx][ny];
            vec.push_back({nx, ny});
            vis[nx][ny] = lab;
        }
    }

    sum = sum / vec.size();
    for (auto& elem : vec) {
        board[elem.X][elem.Y] = sum;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int cnt = 0;
    while (1) {
        int lab = 1;
        clear_vis();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == 0) {
                    bfs(i, j, lab++);
                }
            }
        }
        // print_brd();

        if (lab == (n*n + 1)) break;
        cnt++;
    }

    cout << cnt << '\n';
}
