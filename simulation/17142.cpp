#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;
int board[55][55];
int dist[55][55];
vector<pair<int, int>> virus;
int empty_size;
vector<int> ret;

int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0,  -1};

pair<int, int> arr[15];
bool used[15];

void clear_dist() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = -1;
        }
    }
}

void print_dist() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1) cout << "- ";
            else {
                cout << dist[i][j] << ' ';
            }
        }
    }
}

int check_dist() {
    int maxv = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0) {
                if (dist[i][j] == -1) return -1;
                
                maxv = max(maxv, dist[i][j]);
            }
        }
    }

    return maxv;
}

void func(int k, int r) {
    if (k == m) {
        // for (int i = 0; i < k; i++) {
        //     cout << "{" << arr[i].X << "," << arr[i].Y << "} ";
        // }
        // cout << '\n';

        clear_dist();
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            q.push(arr[i]);
            dist[arr[i].X][arr[i].Y] = 0;
        }

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = cur.X + dirX[i];
                int ny = cur.Y + dirY[i];
                if (nx < 0 || nx > n || ny < 0 || ny > n) continue;
                if (dist[nx][ny] >= 0 || board[nx][ny] == 1) continue;

                q.push({nx, ny});
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            }
        }

        int cr = check_dist();
        if (cr != -1) {
            ret.push_back(cr);
        }

        return;
    }

    for (int i = r; i < virus.size(); i++) {
        if (used[i]) continue;
        used[i] = true;
        arr[k] = virus[i];
        func(k+1, i+1);
        used[i] = false;
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
                virus.push_back({i, j});
            }
            else if (board[i][j] == 0) {
                empty_size++;
            }
        }
    }
    
    func(0, 0);

    if (ret.size() == 0) {
        cout << -1 << '\n';
    }
    else {
        sort(ret.begin(), ret.end());
        cout << ret[0] << '\n';
    }
}