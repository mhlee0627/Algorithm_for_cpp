#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, k;
int dice[4][3];
int board[21][21];

void print_dice() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            cout << dice[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void print_board() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void check_dice() {
    if (board[x][y] != 0) {
        dice[1][1] = board[x][y];
        board[x][y] = 0;
        // cout << "no zero, bottom dice: " << dice[1][1] << "\n";
    }
    else {
        board[x][y] = dice[1][1];
    }
    
    cout << dice[3][1] << "\n";
    // cout << "top dice: " << dice[3][1] << "\n";
}

void rolling_right() {
    if (y+1 >= m) return;
    else y++;

    int bottom = dice[1][1];
    int right = dice[1][2];
    int left = dice[1][0];
    int top = dice[3][1];

    dice[1][1] = right;
    dice[1][0] = bottom;
    dice[3][1] = left;
    dice[1][2] = top;

    check_dice();
}

void rolling_left() {
    if (y-1 < 0) return;
    else y--;

    int bottom = dice[1][1];
    int right = dice[1][2];
    int left = dice[1][0];
    int top = dice[3][1];

    dice[1][1] = left;
    dice[1][2] = bottom;
    dice[3][1] = right;
    dice[1][0] = top;

    check_dice();
}

void rolling_up() {
    if (x-1 < 0) return;
    else x--;

    int front = dice[0][1];
    int bottom = dice[1][1];
    int back = dice[2][1];
    int top = dice[3][1];

    dice[1][1] = front;
    dice[0][1] = top;
    dice[3][1] = back;
    dice[2][1] = bottom;

    check_dice();
}

void rolling_down() {
    if (x+1 >= n) return;
    else x++;

    int front = dice[0][1];
    int bottom = dice[1][1];
    int back = dice[2][1];
    int top = dice[3][1];

    dice[1][1] = back;
    dice[2][1] = top;
    dice[3][1] = front;
    dice[0][1] = bottom;

    check_dice();
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> x >> y >> k;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        cin >> board[i][j];

    int move_dir = 0;
    for (int i = 0; i < k; i++) {
        cin >> move_dir;
        // cout << "cur x,y: " << x << "," << y << "\n";
        // cout << "move_dir: " << move_dir << "\n";
        switch(move_dir) {
            case 1:
                rolling_right();
            break;
            case 2:
                rolling_left();
            break;
            case 3:
                rolling_up();
            break;
            case 4:
                rolling_down();
            break;
        }
    }
}
