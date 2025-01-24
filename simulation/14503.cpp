#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[51][51];
int r, c, d;

void print_board() {
    cout << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void back_up() {
    if (d == 0) r++;
    else if (d == 1) c--;
    else if (d == 2) r--;
    else c++;
}

void move_up() {
    if (d == 0) r--;
    else if (d == 1) c++;
    else if (d == 2) r++;
    else c--;
}

void rotate() {
    if (d == 0) d = 3;
    else if (d == 1) d = 0;
    else if (d == 2) d = 1;
    else d = 2;
}

void action_1() {
    if (board[r][c] == 0) {
        board[r][c] = 2;
    }
}

bool action_2() {
    int back = 0;
    if (d == 0) {
        back = board[r+1][c];
    } 
    else if (d == 1) {
        back = board[r][c-1];
    }
    else if (d == 2) {
        back = board[r-1][c];
    }
    else {
        back = board[r][c+1];
    }

    if (back == 1) {
        return true;
    }
    else {
        back_up();
        return false;   
    }
}

void action_3() {
    rotate();
    int front = 1;
    if (d == 0) {
        front = board[r-1][c];
    }
    else if (d == 1) {
        front = board[r][c+1];
    }
    else if (d == 2) {
        front = board[r+1][c];
    }
    else {
        front = board[r][c-1];
    }

    if (front == 0) {
        move_up();
    }
}

bool is_noclean_room() {
    return !(board[r+1][c] && board[r][c+1] && board[r-1][c] && board[r][c-1]);
}

int count_clean_room() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 2) cnt++;
        }
    }

    return cnt;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> r >> c >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    while (1) {
        action_1();
        if (is_noclean_room()) {
            action_3();
        }
        else {
            if (action_2()) break;
        }
    }

    // print_board();
    cout << count_clean_room();
}