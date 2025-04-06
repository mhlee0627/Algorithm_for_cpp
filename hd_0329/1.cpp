#include <bits/stdc++.h>
using namespace std;

int n, m, r, c;
int board[105][105];
int dir;

void print_board() {
    cout << "print\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

pair<int, int> right_move(int x, int y, int cur) {
    int i = 0;
    for (i = y+1; i <= m; i++) {
        if (board[x][i] > 0) break;
        board[x][i] = ++cur;
    }

    return pair<int, int>(x, i-1);
}

pair<int, int> down_move(int x, int y, int cur) {
    int i = 0;
    for (i = x+1; i <= n; i++) {
        if (board[i][y] > 0) break;
        board[i][y] = ++cur;
    }

    return pair<int, int>(i-1, y);
}

pair<int, int> left_move(int x, int y, int cur) {
    int i = 0;
    for (i = y-1; i >= 1; i--) {
        if (board[x][i] > 0) break;
        board[x][i] = ++cur;
    }

    return pair<int, int>(x, i+1);
}

pair<int, int> up_move(int x, int y, int cur) {
    int i = 0;
    for (i = x-1; i >= 1; i--) {
        if (board[i][y] > 0) break;
        board[i][y] = ++cur;
    }

    return pair<int, int>(i+1, y);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    // pair<int, int> ret1 = right_move(1, 0, 0);
    // cout << "ret1:" << ret1.first << ", " << ret1.second << '\n';
    // pair<int, int> ret2 = down_move(ret1.first, ret1.second, board[ret1.first][ret1.second]);
    // cout << "ret2:" << ret2.first << ", " << ret2.second << '\n';
    // pair<int, int> ret3 = left_move(ret2.first, ret2.second, board[ret2.first][ret2.second]);
    // cout << "ret3:" << ret3.first << ", " << ret3.second << '\n';
    // pair<int, int> ret4 = up_move(ret3.first, ret3.second, board[ret3.first][ret3.second]);
    // cout << "ret4:" << ret4.first << ", " << ret4.second << '\n';

    pair<int, int> ret = pair<int, int>(1, 0);
    while (true) {
        if (dir%4 == 0) {
            ret = right_move(ret.first, ret.second, board[ret.first][ret.second]);
            dir++;
        }
        else if (dir%4 == 1) {
            ret = down_move(ret.first, ret.second, board[ret.first][ret.second]);
            dir++;
        }
        else if (dir%4 == 2) {
            ret = left_move(ret.first, ret.second, board[ret.first][ret.second]);
            dir++;
        }
        else {
            ret = up_move(ret.first, ret.second, board[ret.first][ret.second]);
            dir++;
        }

        if (board[ret.first][ret.second] == n*m) break;
    }

    print_board();

}