#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

queue<pair<int, int>> q;
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};

int t, w, h;
string board[1001];
int s_dist[1001][1001];
int f_dist[1001][1001];
int result = -1;
pair<int, int> s_pos;
vector<pair<int, int>> f_pos;

void s_dist_clear() {
    for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
        s_dist[i][j] = -1;
}

void s_dist_print() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << setw(2) << s_dist[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void f_dist_clear() {
    for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
        f_dist[i][j] = -1;
}

void f_dist_print() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << setw(2) << f_dist[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void f_bfs() {
    f_dist_clear();
    
    for (auto& elem : f_pos) {
        q.push({elem.X, elem.Y});
        f_dist[elem.X][elem.Y] = 0;
    }

    while (!q.empty()) {
        pair<int, int> curPos = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = curPos.X + dirX[i];
            int ny = curPos.Y + dirY[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (board[nx][ny] == '#' || f_dist[nx][ny] > -1) continue;
            q.push({nx, ny});
            f_dist[nx][ny] = f_dist[curPos.X][curPos.Y] + 1;
        }
    }
}

void s_bfs() {
    s_dist_clear();

    q.push({s_pos.X, s_pos.Y});
    s_dist[s_pos.X][s_pos.Y] = 0;
    while (!q.empty()) {
        pair<int, int> curPos = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = curPos.X + dirX[i];
            int ny = curPos.Y + dirY[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
                // cout << "exit!!\n";
                result = s_dist[curPos.X][curPos.Y] + 1;
                return;
            }
            if (board[nx][ny] != '.') continue;
            if (s_dist[nx][ny] > -1) continue;
            if ((f_dist[nx][ny] != -1) && ((s_dist[curPos.X][curPos.Y] + 1) >= f_dist[nx][ny])) continue;
            
            // cout << "\n";
            // cout << "f_dist: " << f_dist[nx][ny] << "\n";
            // cout << "s_dist: " << s_dist[nx][ny] << "\n";
            // cout << "push: " << nx << ", " << ny << "\n";
            q.push({nx, ny});
            s_dist[nx][ny] = s_dist[curPos.X][curPos.Y] + 1;
        }
    }
}

void init() {
    result = -1;
    f_pos.clear();
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> w >> h;
        for (int i = 0; i < h; i++) {
            cin >> board[i];
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (board[i][j] == '@')
                    s_pos = {i, j};
                else if (board[i][j] == '*')
                    f_pos.push_back({i, j});
            }
        }

        f_bfs();
        // f_dist_print();
        s_bfs();
        // s_dist_print();

        if (result == -1) 
            cout << "IMPOSSIBLE\n";
        else
            cout << result << "\n";

        init();
    }
}