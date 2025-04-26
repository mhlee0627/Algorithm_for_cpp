#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;
int board[10][10];
bool vis[10][10];
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};
vector<pair<int, int>> v_pos_list;
int zero_cnt;
int max_val;

void clear_vis() {
    for (int i = 0 ; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vis[i][j] = 0;
        }
    }
}

int bfs(int x, int y) {
    int ret = 0;

    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = true;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = dirX[i] + cur.X;
            int ny = dirY[i] + cur.Y;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (board[nx][ny] != 0 || vis[nx][ny] == true) continue;

            q.push({nx, ny});
            vis[nx][ny] = true;
            ret++;
        }
    }
    
    return ret;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                v_pos_list.push_back({i, j});
            }
            else if (board[i][j] == 0) {
                zero_cnt++;
            }
        }
    }

    vector<pair<int, int>> coords;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            coords.emplace_back(i, j);
        }
    }

    int nn = coords.size();
    for (int i = 0; i < nn; i++) {
        for (int j = i + 1; j < nn; j++) {
            for (int k = j + 1; k < nn; k++) {
                if (board[coords[i].X][coords[i].Y] != 0) continue;
                if (board[coords[j].X][coords[j].Y] != 0) continue;
                if (board[coords[k].X][coords[k].Y] != 0) continue;
                
                board[coords[i].X][coords[i].Y] = 1;
                board[coords[j].X][coords[j].Y] = 1;
                board[coords[k].X][coords[k].Y] = 1;

                int t_ret = 0;
                for (auto& elem : v_pos_list) {
                    t_ret += bfs(elem.X, elem.Y);
                }

                max_val = max(max_val, zero_cnt - t_ret - 3);

                board[coords[i].X][coords[i].Y] = 0;
                board[coords[j].X][coords[j].Y] = 0;
                board[coords[k].X][coords[k].Y] = 0;

                clear_vis();
            }
        }
    }

    cout << max_val << '\n';
}