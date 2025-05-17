#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define MAX_TIME 55 * 55

int n, m;
int board[55][55];
int dist[55][55];
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};
vector<pair<int, int>> available_virus_pos;
int select_virus_pos[15];
int min_time = MAX_TIME;

void clear_dist() {
    for (int i = 0; i < n; i++) {
        for (int j =0; j < n; j++) {
            dist[i][j] = -1;
        }
    }
}

void print_dist() {
    cout << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int check_dist() {
    int ans = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == -1 && board[i][j] != 1) return MAX_TIME;
            if (dist[i][j] >= 0) {
                ans = max(ans, dist[i][j]);
            }
        }
    }

    return ans;
}

void func(int k) {
    if (k == m) {
        clear_dist();
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            // cout << "(" << available_virus_pos[select_virus_pos[i]].first << ", " << available_virus_pos[select_virus_pos[i]].second << ") ";
            q.push(available_virus_pos[select_virus_pos[i]]);
            dist[available_virus_pos[select_virus_pos[i]].X][available_virus_pos[select_virus_pos[i]].Y] = 0;
        }

        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = cur.X + dirX[i];
                int ny = cur.Y + dirY[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (board[nx][ny] == 1 || dist[nx][ny] >= 0) continue;

                q.push({nx, ny});
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            }
        }

        // print_dist();
        // cout << "check ret: " << check_dist() << '\n';
        int cur_time = check_dist();
        if (cur_time >= 0) {
            min_time = min(min_time, cur_time);
        }
        
        return;
    }

    int st = 0;
    if (k != 0) st = select_virus_pos[k-1] + 1;

    for (int i = st; i < available_virus_pos.size(); i++) {
        select_virus_pos[k] = i;
        func(k+1);
    }
}

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                available_virus_pos.emplace_back(i, j);
            }
        }
    }

    func(0);

    if (min_time == MAX_TIME) {
        cout << -1 << '\n';
    }
    else {
        cout << min_time << '\n';
    }
}