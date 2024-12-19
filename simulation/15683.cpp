#include <bits/stdc++.h>
using namespace std;

int n, m;
int min_value = 68;
char board[8][8];
bool vis[8];
// queue<tuple<int, int, char>> cctv_pos;
vector<tuple<int, int, char>> cctv_pos;
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
    else if (dir == 1) {
        up_draw(x, y);
        down_draw(x, y);
    }
    else if (dir == 2) {
        left_draw(x, y);
        right_draw(x, y);
    }
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

    for (int i = (y+1); i < m; i++) {
        if (board[x][i] == '6') break;
        if (board[x][i] == '0') {
            board[x][i] = '7';
        }
    }

    for (int i = (x+1); i < n; i++) {
        if (board[i][y] == '6') break;
        if (board[i][y] == '0') {
            board[i][y] = '7';
        }
    }

    for (int i = (y-1); i > -1; i--) {
        if (board[x][i] == '6') break;
        if (board[x][i] == '0') {
            board[x][i] = '7';
        }
    }

    for (int i = (x-1); i > -1; i--) {
        if (board[i][y] == '6') break;
        if (board[i][y] == '0') {
            board[i][y] = '7';
        }
    }
}

void cctv_draw(int x, int y, int dir, char cctv) {
    switch(cctv) {
        case '1': 
            cctv_1_draw(x, y, dir);
            break;
        case '2':
            cctv_2_draw(x, y, dir);
            break;
        case '3':
            cctv_3_draw(x, y, dir);
            break;
        case '4':
            cctv_4_draw(x, y, dir);
            break;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == '1') cctv_pos.push_back(make_tuple(i, j, '1'));
            else if (board[i][j] == '2') cctv_pos.push_back(make_tuple(i, j, '2'));
            else if (board[i][j] == '3') cctv_pos.push_back(make_tuple(i, j, '3'));
            else if (board[i][j] == '4') cctv_pos.push_back(make_tuple(i, j, '4'));
            else if (board[i][j] == '5') cctv5_pos.push({i, j});
            else ;
        }
    }

    while(!cctv5_pos.empty()) {
        pair<int, int> cctv5 = cctv5_pos.front(); cctv5_pos.pop();
        cctv_5_draw(cctv5.first, cctv5.second, 0);
    }

    int size = cctv_pos.size();
    // cout << "cctv_pos size: " << size << "\n";

    for (int tmp = 0; tmp < pow(4, size); tmp++) {
        int brute = tmp;
        for (int i = 0; i < size; i++) {
            tuple<int, int, char> cur = cctv_pos[i];
            cctv_draw(get<0>(cur), get<1>(cur), (brute%4), get<2>(cur));
            brute /= 4;
        }
        // board_print();
        int cur_min = count_zero();
        min_value = min_value > cur_min ? cur_min : min_value;
        // cout << "zero cnt: " << min_value << "\n";
        board_clear();
    }

    cout << min_value;
}