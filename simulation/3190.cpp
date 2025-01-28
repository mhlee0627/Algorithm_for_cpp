#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, k, l, x;
char c;
vector<pair<int, int>> snake_pos;
map<int, char> snake_dir;
int second;
char d = 1; // North(0) East(1) South(2) West(3)

int board[105][105];

// check print
int c_board[105][105];

void ac_1() {
    pair<int, int> tmp_head = snake_pos.back();

    if (d == 0) {
        tmp_head.X--;
    }
    else if (d == 1) {
        tmp_head.Y++;
    }
    else if (d == 2) {
        tmp_head.X++;
    }
    else {
        tmp_head.Y--;
    }

    snake_pos.push_back(tmp_head);
}

bool ac_2() {
    pair<int, int> cur_haed = snake_pos.back();

    if (cur_haed.X < 0 || cur_haed.X >= n || cur_haed.Y < 0 || cur_haed.Y >= n) return false;

    for (int i = 0; i < snake_pos.size()-1; i++) {
        pair<int, int> cur_body = snake_pos[i];
        
        if (cur_body == cur_haed) return false;
    }

    return true;
}

void ac_34() {
    pair<int, int> cur_haed = snake_pos.back();

    if (board[cur_haed.X][cur_haed.Y] == 1) {
        board[cur_haed.X][cur_haed.Y] = 0;
    }
    else {
        snake_pos.erase(snake_pos.begin());
    }
}

void change_dir(char td) {
    if (td == 'D') {
        d = (d+1)%4;
    }
    else {
        d--;
        if (d < 0) d = 3;
    }
}

void check_print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (c_board[i][j] == 1) continue;
            c_board[i][j] = 0;
        }
    }

    for (auto elem : snake_pos) {
        c_board[elem.X][elem.Y] = 4;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << c_board[i][j];
        }
        cout << "\n";
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    int tx, ty;
    for (int i = 0; i < k; i++) {
        cin >> tx >> ty;
        board[tx-1][ty-1] = 1;
        
        c_board[tx-1][ty-1] = 1;
    }

    cin >> l;
    for (int i = 0; i < l; i++) {
        cin >> x >> c;
        snake_dir[x] = c;
    }

    snake_pos.push_back({0, 0});

    while (1) {
        second++;
        ac_1();
        if (!ac_2()) break;
        ac_34();

        auto itr = snake_dir.find(second);
        if (itr != snake_dir.end()) {
            change_dir(itr->Y);
        }

        // cout << "second: " << second << "\n";
        // check_print();
        // cout << "\n";
    }

    cout << second;
}