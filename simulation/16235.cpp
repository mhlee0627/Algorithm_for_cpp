#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int grow[15][15];
vector<int> board[15][15];
int resource[15][15];

int dirX[8] = {1, 0, -1, 0, -1, 1, -1,  1};
int dirY[8] = {0, 1, 0, -1, -1, 1,  1, -1};

void springsummer_turn() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j].size() == 0) continue;

            // spring
            auto& v = board[i][j];
            int idx = (int)v.size() - 1;
            for (; idx >= 0; idx--) {
                if (resource[i][j] < v[idx]) break;
                resource[i][j] -= v[idx];
                v[idx]++;
            }
            
            // summer
            for (int t = 0; t <= idx; t++) resource[i][j] += v[t]/2;

            v.erase(v.begin(), v.begin() + idx + 1);
        }
    }
}

void fall_turn() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j].size() == 0) continue;

            for (auto age : board[i][j]) {
                if (age%5 != 0) continue;

                for (int k = 0; k < 8; k++) {
                    int nx = i + dirX[k];
                    int ny = j + dirY[k];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    board[nx][ny].push_back(1);
                }
            }
        }
    }
}

void winter_turn() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            resource[i][j] += grow[i][j];
        }
    }
}

int count_tree() {
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cnt += board[i][j].size();
        }
    }

    return cnt;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grow[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        board[a-1][b-1].push_back(c);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            resource[i][j] = 5;
        }
    }

    while (k--) {
        springsummer_turn();
        fall_turn();
        winter_turn();
    }

    cout << count_tree() << '\n';
}
