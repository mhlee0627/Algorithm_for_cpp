#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

#define W 0
#define R 1
#define B 2

#define RW 1
#define LF 2
#define UP 3
#define DW 4

int dirX[5] = {0, 0,  0, -1, 1};
int dirY[5] = {0, 1, -1,  0, 0};

int n, k;
int board[15][15];
deque<pair<int, int>> node[15][15];   // first number, second dir
bool actor[15];
pair<int, int> pos[15];

string cv2dir(int dir) {
    if (dir == RW) return string("RW");
    if (dir == LF) return string("LF");
    if (dir == DW) return string("DW");
    if (dir == UP) return string("UP");
    return "";
}

void print() {
    for (int i = 1; i <= k; i++) {
        if (actor[i]) {
            auto cur = pos[i];
            cout << "actor: " << i << " / dir: " << cv2dir(node[cur.X][cur.Y].front().second) << " / dqeue: ";
            for (auto elem : node[cur.X][cur.Y]) {
                cout << elem.X << ' ';
            }
            cout << '\n';
        }
    }

    cout << '\n';
}

void init_board() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            board[i][j] = B;
        }
    }
}

int convertdir(int dir) {
    if (dir == RW) return LF;
    else if (dir == LF) return RW;
    else if (dir == UP) return DW;
    else return UP;
}

void func(int idx, bool twice) {
    if (actor[idx]) {
        pair<int, int> cur_pos = pos[idx];
        int dir = node[cur_pos.X][cur_pos.Y].front().second;
        pair<int, int> nxt_pos = {cur_pos.X + dirX[dir], cur_pos.Y + dirY[dir]};

        if (board[nxt_pos.X][nxt_pos.Y] == W) {
            while (!node[cur_pos.X][cur_pos.Y].empty()) {
                auto elem = node[cur_pos.X][cur_pos.Y].front();
                node[cur_pos.X][cur_pos.Y].pop_front();
                node[nxt_pos.X][nxt_pos.Y].push_back(elem);
            }

            auto ac = node[nxt_pos.X][nxt_pos.Y].front();
            actor[idx] = false;
            pos[idx] = {nxt_pos.X, nxt_pos.Y};
            actor[ac.first] = true;
            pos[ac.first] = {nxt_pos.X, nxt_pos.Y};
        }
        else if (board[nxt_pos.X][nxt_pos.Y] == R) {
            while (!node[cur_pos.X][cur_pos.Y].empty()) {
                auto elem = node[cur_pos.X][cur_pos.Y].back();
                node[cur_pos.X][cur_pos.Y].pop_back();
                node[nxt_pos.X][nxt_pos.Y].push_back(elem);
            }

            auto ac = node[nxt_pos.X][nxt_pos.Y].front();
            actor[idx] = false;
            pos[idx] = {nxt_pos.X, nxt_pos.Y};
            actor[ac.first] = true;
            pos[ac.first] = {nxt_pos.X, nxt_pos.Y};
        }
        else {
            if (!twice) {
                auto elem = node[cur_pos.X][cur_pos.Y].front();
                node[cur_pos.X][cur_pos.Y].pop_front();
                elem = {elem.X, convertdir(elem.Y)};
                node[cur_pos.X][cur_pos.Y].push_front(elem);

                func(idx, true);
            }
        }
    }
}

bool check() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (node[i][j].size() >= 4) return true;
        }
    }

    return false;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    init_board();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 1; i <= k; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        pos[i] = {x, y};
        actor[i] = true;
        node[x][y].push_back({i, z});
    }
    
    int ret = 0;
    while (1) {
        for (int i = 1; i <= k; i++) {
            func(i, false);
        }

        ret++;
        if (ret > 1000) {
            cout << -1 << '\n';
            return 0;
        }
        
        if (check()) {
            cout << ret << '\n';
            return 0;
        }
    }
}