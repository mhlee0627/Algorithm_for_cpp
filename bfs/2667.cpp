#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

string board[26];
int num_b[26][26];
int n;
queue<pair<int, int>> q;
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};

int cnt;
int num = 1;
vector<int> cnt_vec;

void bfs(int x, int y) {
    q.push({x, y});
    num_b[x][y] = num;
    cnt++;
    while (!q.empty()) {
        pair<int, int> cur_pos = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur_pos.X + dirX[i];
            int ny = cur_pos.Y + dirY[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (board[nx][ny] == '0' || num_b[nx][ny] > 0) continue;
            q.push({nx, ny});
            num_b[nx][ny] = num;
            cnt++;
        }
    }

    num++;
    cnt_vec.push_back(cnt);
    cnt = 0;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
       cin >> board[i]; 
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '1' && num_b[i][j] == 0) {
                bfs(i, j);
            }
        }
    }

    // cout << "\n";
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << num_b[i][j];
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";


    cout << cnt_vec.size() << "\n";
    sort(cnt_vec.begin(), cnt_vec.end());
    for (auto elem : cnt_vec) {
        cout << elem << "\n";
    }
}