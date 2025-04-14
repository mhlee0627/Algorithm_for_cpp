#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n;
int board[25][25];
int shark_size = 2;
int shark_eat_fish_count = 0;
pair<int, int> shark_pos;
int eat_time;

int dist[25][25];
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};

void clear_dist() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
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
}

void print_board() {
    cout << "\neat_time: " << eat_time << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

void bfs() {
    queue<pair<int, int>> q;

    dist[shark_pos.X][shark_pos.Y] = 0;
    q.push({shark_pos.X, shark_pos.Y});

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = dirX[i] + cur.X;
            int ny = dirY[i] + cur.Y;
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (dist[nx][ny] >= 0) continue;
            
            if (board[nx][ny] > shark_size) continue;

            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            q.push({nx, ny});
        }
    }
}

bool check_eat_fish() {
    bool ret = false;
    
    int fish_dist_min = 0x7fffffff;
    pair<int, int> fish_dist_min_pos;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] >= 1 && (board[i][j] < shark_size)) {
                if (dist[i][j] >= 1 && fish_dist_min > dist[i][j]) {
                    fish_dist_min = dist[i][j];
                    fish_dist_min_pos = {i, j};
                    ret = true;
                }
            }
        }
    }

    if (ret) {        
        board[shark_pos.X][shark_pos.Y] = 0;
        shark_pos = {fish_dist_min_pos.X, fish_dist_min_pos.Y};
        eat_time += fish_dist_min;
        board[shark_pos.X][shark_pos.Y] = 9;

        shark_eat_fish_count++;
        if (shark_eat_fish_count == shark_size) {
            shark_size++;
            if (shark_size >= 7) {
                shark_size = 7;
            }
            shark_eat_fish_count = 0;
        }

        return true;
    }
    else {
        return false;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                shark_pos = {i, j};
            }
        }
    }

    while (1) {
        clear_dist();
        bfs();
        if (!check_eat_fish()) {
            // print_board();
            break;
        }
        // print_board();
    }

    cout << eat_time << '\n';
}