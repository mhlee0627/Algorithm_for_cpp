#include <bits/stdc++.h>
using namespace std;

int n, m;
int min;
char board[8][8];
// queue<tuple<int, int, char>> cctv_pos;
queue<pair<int, int>> cctv1_pos;
queue<pair<int, int>> cctv2_pos;
queue<pair<int, int>> cctv3_pos;
queue<pair<int, int>> cctv4_pos;
queue<pair<int, int>> cctv5_pos;

void board_clear() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '#') board[i][j] = '0';
        }
    }
}

void board_print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

int count_zero() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '0') cnt++;
        }
    }

    return cnt;
}

void right_draw(int x, int y) {
    for (int i = (y+1); i < m; i++) {
        if (board[x][i] == '6') break;
        if (board[x][i] == '0') {
            board[x][i] = '#';
        }
    }
}

void down_draw(int x, int y) {
    for (int i = (x+1); i < n; i++) {
        if (board[i][y] == '6') break;
        if (board[i][y] == '0') {
            board[i][y] = '#';
        }
    }
}

void left_draw(int x, int y) {
    for (int i = (y-1); i > -1; i--) {
        if (board[x][i] == '6') break;
        if (board[x][i] == '0') {
            board[x][i] = '#';
        }
    }
}

void up_draw(int x, int y) {
    for (int i = (x-1); i > -1; i--) {
        if (board[i][y] == '6') break;
        if (board[i][y] == '0') {
            board[i][y] = '#';
        }
    }
}

void cctv_1_draw(int x, int y, int dir) {
    // right
    if (dir == 0)
        right_draw(x, y);
    // down
    else if (dir == 1)
        down_draw(x, y);
    // left
    else if (dir == 2)
        left_draw(x, y);
    // up
    else
        up_draw(x, y);
}

void cctv_2_draw(int x, int y, int dir) {
    // left and right
    if (dir == 0) {
       left_draw(x, y);
       right_draw(x, y);
    }
    // up and down
    else {
        up_draw(x, y);
        down_draw(x, y);
    }
}

void cctv_3_draw(int x, int y, int dir) {
    // up and right
    if (dir == 0) {
        up_draw(x, y);
        right_draw(x, y);
    }
    // right and down
    else if (dir == 1) {
        right_draw(x, y);
        down_draw(x, y);
    }
    // down and left
    else if (dir == 2) {
        down_draw(x, y);
        left_draw(x, y);
    }
    // left and up
    else {
        left_draw(x, y);
        up_draw(x, y);
    }
}

void cctv_4_draw(int x, int y, int dir) {
    // up and right and left
    if (dir == 0) {
        up_draw(x, y);
        right_draw(x, y);
        left_draw(x, y);
    }
    // up and right and dwon
    else if (dir == 1) {
        up_draw(x, y);
        right_draw(x, y);
        down_draw(x, y);
    }
    // right and down and left
    else if (dir == 2) {
        right_draw(x, y);
        down_draw(x, y);
        left_draw(x, y);
    }
    // down and left and up
    else {
        down_draw(x, y);
        left_draw(x, y);
        up_draw(x, y);
    }
}

void cctv_5_draw(int x, int y, int dir) {
    // all dir
    up_draw(x, y);
    right_draw(x, y);
    down_draw(x, y);
    left_draw(x, y);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == '1') cctv1_pos.push({i, j});
            else if (board[i][j] == '2') cctv2_pos.push({i, j});
            else if (board[i][j] == '3') cctv3_pos.push({i, j});
            else if (board[i][j] == '4') cctv4_pos.push({i, j});
            else if (board[i][j] == '5') cctv5_pos.push({i, j});
            else ;
        }
    }

    while(!cctv5_pos.empty()) {
        pair<int, int> cctv5 = cctv5_pos.front(); cctv5_pos.pop();
        cctv_5_draw(cctv5.first, cctv5.second, 0);
    }

    
    

}